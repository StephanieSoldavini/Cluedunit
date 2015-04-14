import java.util.ArrayList;

/**
 * Created by Stephanie on 2/16/15.
 */
public class Char extends Card {
    public static ArrayList<Char> characters = new ArrayList<>();
    String abbr;
    String color;

    public Char(String name, String abbr, String color) {
        super(name);
        this.abbr = abbr;
        this.color = color;
        Char.characters.add(this);
    }

    @Override
    public String toString() {
        return this.name;
    }

}
