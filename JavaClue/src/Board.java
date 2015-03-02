import java.util.ArrayList;

/**
 * Created by Stephanie on 2/20/15.
 */
public class Board {
    int width;
    int height;
    ArrayList<String> rooms = new ArrayList<>();
    ArrayList<ArrayList<String>> board = new ArrayList<>();


    public Board(int width, int height, ArrayList<String> rooms) {
        this.width = width;
        this.height = height;
        this.rooms = rooms;
        //create empty nested list board
        for (int x=0; x<this.width; x++) {
            board.add(new ArrayList<String>());
            for (int y=0; y<this.height; y++) {
                board.get(x).add("");
            }
        }
        //add to board

    }

}
