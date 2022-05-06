#include "Board.h"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

TEST(Board, test1) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c',7))->getType(), Type::PAWN);
	delete board;
}
TEST(Board, test2) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c', 7))->getColor(), Color::BLACK);
	delete board;
}

TEST(Board, test3) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c', 2))->getType(), Type::PAWN);
	delete board;
}
TEST(Board, test4) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c', 2))->getColor(), Color::WHITE);
	delete board;
}

TEST(Board, test5) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c', 1))->getType(), Type::BISHOP);
	delete board;
}
TEST(Board, test6) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c', 1))->getColor(), Color::WHITE);
	delete board;
}

TEST(Board, test7) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c', 8))->getType(), Type::BISHOP);
	delete board;
}
TEST(Board, test8) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c', 8))->getColor(), Color::BLACK);
	delete board;
}

TEST(Board, test9) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('h', 1))->getType(), Type::ROOK);
	delete board;
}
TEST(Board, test10) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('h', 1))->getColor(), Color::WHITE);
	delete board;
}

TEST(Board, test11) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('h', 8))->getType(), Type::ROOK);
	delete board;
}
TEST(Board, test12) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('h', 8))->getColor(), Color::BLACK);
	delete board;
}

TEST(Board, test13) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('b', 1))->getType(), Type::KNIGHT);
	delete board;
}
TEST(Board, test14) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('b', 1))->getColor(), Color::WHITE);
	delete board;
}

TEST(Board, test15) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('b', 8))->getType(), Type::KNIGHT);
	delete board;
}
TEST(Board, test16) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('b', 8))->getColor(), Color::BLACK);
	delete board;
}

TEST(Board, test17) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('d', 1))->getType(), Type::QUEEN);
	delete board;
}
TEST(Board, test18) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('d', 1))->getColor(), Color::WHITE);
	delete board;
}

TEST(Board, test19) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('d', 8))->getType(), Type::QUEEN);
	delete board;
}
TEST(Board, test20) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('d', 8))->getColor(), Color::BLACK);
	delete board;
}

#endif