#include "Board.h"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

TEST(Board, simple) {
	using namespace gamelogic;
	Board* board = new Board();
	board->createPieces();
	EXPECT_EQ(board->getPiece(std::make_tuple('c',7))->getType(), Type::PAWN);
	delete board;
}

#endif