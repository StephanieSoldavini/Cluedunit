/**
 * Created by Stephanie on 2/16/15.
 */
public class Char extends Card {
    String abbr;
    String color;

    public Char(String name, String abbr, String color) {
        super(name);
        this.abbr = abbr;
        this.color = color;
    }

    @Override
    public String toString() {
        return this.name;
    }

}
