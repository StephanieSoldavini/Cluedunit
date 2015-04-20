/**
 * For holding guesses
 * Created by andrew on 4/19/15.
 */
public class Guess {
    private Weapon weapon;
    private Room room;
    private Char aChar;

    /**
     * What did the person guess
     * @param weapon what weapon was it
     * @param room what room was it
     * @param aChar which character was it
     */
    public Guess(Weapon weapon, Room room, Char aChar){
        this.weapon = weapon;
        this.room = room;
        this.aChar = aChar;
    }

    public Char getaChar() {
        return aChar;
    }

    public Room getRoom() {
        return room;
    }

    public Weapon getWeapon() {
        return weapon;
    }
}
