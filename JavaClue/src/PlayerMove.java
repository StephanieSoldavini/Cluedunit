/**
 * Used to describe what a player has done. Will need two per turn (one for move and one for guess)
 * Created by andrew on 4/14/15.
 */
public class PlayerMove {
    private final int playerId;
    private final boolean isMove;
    private final Loc endLoc;
    private final Guess guess;

    /**
     * When the player is guessing
     */
    public PlayerMove(int playerId, boolean isMove, Guess guess){
        this(playerId, isMove, null, guess);
    }

    /**
     * When the player is moving
     */
    public PlayerMove(int playerId, boolean isMove, Loc endLoc){
        this(playerId, isMove, endLoc, null);
    }

    /**
     *
     * @param playerId which player am I (probably same as order)
     * @param isMove did I move
     * @param endLoc where did the player go
     * @param guess what did the player guess
     */
    public PlayerMove(int playerId, boolean isMove, Loc endLoc, Guess guess){
        this.playerId = playerId;
        this.isMove = isMove;
        this.endLoc = endLoc;
        this.guess = guess;
    }

    public int getPlayerId() {
        return playerId;
    }

    public boolean isMove() {
        return isMove;
    }

    public Loc getEndLoc() {
        return endLoc;
    }

    public Guess getGuess() {
        return guess;
    }
}
