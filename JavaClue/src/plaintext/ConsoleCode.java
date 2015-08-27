package plaintext;

/**
 * Created by Stephanie on 8/26/15.
 */
public class ConsoleCode {
    public static String goTo(int row, int col, boolean ascii){
        if (ascii) {
            return "\33[" + row + ";" + col + "H";
        }
        else {
            return "\33[" + (2*row + 2) + ";" + (5*col + 3) + "H";
        }
    }



    public static String changeTextColor(String color){
        switch (color){
            case "red":
                return "\33[0;31m";
            case "green":
                return "\33[0;32m";
            case "yellow":
                return "\33[0;33m";
            case "blue":
                return "\33[1;34m";
            case "purple":
                return "\33[0;35m";
            case "white":
                return "\33[0;37m";
            default:
                return "\33[0m";
        }
    }

}
