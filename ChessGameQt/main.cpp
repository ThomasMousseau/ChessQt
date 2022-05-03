/*
* \file   main.cpp
* \author Matteo Colavita et Thomas Mousseau
* \date   25 avril 2022
* Créé le 20 avril 2022
*/

#include <QApplication>
#include "Raii.h"
#include "ChessWindow.h"

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char *argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);

	QGraphicsScene* scene = new QGraphicsScene();
	QGraphicsView* view = new QGraphicsView(scene);
	QBrush* brush = new QBrush(Qt::lightGray, Qt::SolidPattern);
	
	view->setBackgroundBrush(*brush);

	graphicinterface::ChessWindow chessWindow(scene);
	gamelogic::Board* board = new gamelogic::Board();

	for(auto&& tile: board->getTiles())
	{
		QObject::connect(tile, SIGNAL(tileTextModified(std::tuple<char,int>, std::string)), &chessWindow, SLOT(addPiece(std::tuple<char, int>, std::string)));
		QObject::connect(&chessWindow, SIGNAL(tileSelected(std::tuple<char, int>)), board, SLOT(findValidMoves(std::tuple<char, int>)));
	}

	try
	{
		board->createPieces();
		board->createKings();
	}
	catch (TooManyKingsException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(qobject_cast<QWidget*>(scene), "QTERROR", e.what());
	}

	chessWindow.setCentralWidget(view);
	chessWindow.show();

	Raii aquisitionBoard(board);
	Raii aquisitionScene(scene);
	Raii aquisitionView(view);
	Raii aquisitionBrush(brush);
	return app.exec();
}
