package engine;

import java.util.ArrayList;

/**
 * Created by Stephanie on 2/16/15.
 */
public class Char extends Card {
    public static ArrayList<Char> characters = new ArrayList<>();

    public static Char getCharByAbbr(String abbrev){
        return Char.characters.stream().filter(p -> p.getAbbr().equals(abbrev)).findFirst().get();
    }

    public String getAbbr() {
        return abbr;
    }


    private String abbr;

    public String getColor() {
        return color;
    }

    private String color;

    public Loc getHome() {
        return home;
    }

    private Loc home;

    public Char(String name, String abbr, String color, int row, int col) {
        super(name);
        this.abbr = abbr;
        this.color = color;
        this.home = new Loc(col, row, name + " Home", null);
        Char.characters.add(this);
    }

    @Override
    public String toString() {
        return this.name;
    }

}
