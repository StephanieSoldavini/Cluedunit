import java.lang.reflect.Array;
import java.util.ArrayList;

/**
 * Used to describe a card. Knows who has seen it, and who holds it
 * Created by Stephanie on 2/16/15.
 */
public class Card {
    String name;
    private Player heldBy;
    private java.util.ArrayList<Player> seenBy;

    public Card(String name) {
        this.name = name;
    }

    public void showTo(Player player) {
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Card)) return false;

        Card card = (Card) o;

        if (!name.equals(card.name)) return false;

        return true;
    }

    @Override
    public int hashCode() {
        return name.hashCode();
    }

    /**
     * Calls constructors for child classes based on cards.txt
     * Child constructors create static arraylists in respective classes
     */
    public static void createAllCards(){
        ArrayList<ArrayList<String>> cards = FileReader.parseFileAsList("data/cards.txt");
        for (ArrayList<String> card : cards){
            if (card.get(0).equals("C")){
                new Char(card.get(1).trim(), card.get(2).trim(), null);
            } else if (card.get(0).equals("W")) {
                new Weapon(card.get(1).trim(), null);
            } else if (card.get(0).equals("R")) {
                new Room(card.get(1).trim());
            }
        }
    }

}
