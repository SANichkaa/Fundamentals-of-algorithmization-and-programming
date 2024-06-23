#include "piece_promotion_manager.h"

bool PiecePromotionManager::checkPromotionEligibility(const Piece& piece)
{
    if(piece.isPromoted())
    {
        return false;
    }

    const Player piecePlayer = piece.getPlayer();
    const Coordinates pieceCoordinates(piece.getRow(), piece.getColumn());

    if(piecePlayer == Player::LOWER)
    {
        if(pieceCoordinates.getRow() == 1)
        {
            return true;
        }
    }
    else if(piecePlayer == Player::UPPER)
        {
            if(pieceCoordinates.getRow() == 8)
            {
                return true;
            }
        }

    return false;
}
