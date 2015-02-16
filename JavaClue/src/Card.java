/**
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

}
