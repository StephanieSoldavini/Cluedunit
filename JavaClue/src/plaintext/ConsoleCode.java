package plaintext;

/**
 * Created by Stephanie on 8/26/15.
 */

public class ConsoleCode {
    /**
     * Put the cursor at the provided (row, col) where the origin is the conservatory
     *
     * @param row number of spaces horizontally from origin
     * @param col number of spaces vertically from origin
     * @param ascii true if coords represent the actual cursor location, false if board location
     * @return a string to print to console to perform the operation
     */
    public static String goTo(int row, int col, boolean ascii){
        if (ascii) {
            return "\33[" + row + ";" + col + "H";
        }
        else {
            return "\33[" + (2*row + 2) + ";" + (5*col + 3) + "H";
        }
    }

    /**
     * Clear from the cursor to the end of the console window
     *
     * @return a string to print to console to perform the operation
     */
    public static String clearToEnd(){
        return "\33[J";
    }

    /**
     * Change the font color
     *
     * @param color the color to change to
     * @return a string to print to console to perform the operation
     */
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
