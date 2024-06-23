#ifndef PIECE_STATE_MANAGER_H
#define PIECE_STATE_MANAGER_H
#include "piece.h"

class PieceStateManager
{
public:
    static void selectPiece(Piece& piece);
    static void deselectPiece(Piece& piece);
    static void disablePiece(Piece& piece);
    static void markPieceHasValidMovePossible(Piece& piece);
};

#endif // PIECE_STATE_MANAGER_H
