import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Convenience class for programmers who don't know file
 * input/output in Java. ... yet
 */
public class FileReader {
    /**
     * Produce a Scanner instance connected to the given file.
     * If the file cannot be opened, this method will report
     * it on standard error, and then terminate the program
     * with a status of 1.
     * @param fileName the name of the file to be scanned
     * @return a Scanner instance on the file. (Please close it when done!)
     */
    public static Scanner openFile( String fileName ) {
        Scanner result = null;
        try {
            InputStream istream = new FileInputStream( fileName );
            result = new Scanner( istream );
        }
        catch ( FileNotFoundException fnfe ) {
            System.err.println( fnfe );
            System.err.println( "File \"" + fileName + "\" does not exist." );
            System.exit( 1 );
        }
        return result;
    }

    /**
     * Each item in the file separated by a semicolon becomes an entry in a list.
     * This list encompasses all items in the same row, and is added to a list that contains other lists of rows
     * @param fileName name of file with location
     * @return lists inside of lists
     */
    public static ArrayList<ArrayList<String>> parseFileAsList( String fileName ) {
        ArrayList<ArrayList<String>> lst = new ArrayList<>();
        Scanner scan = openFile(fileName);
        while (scan.hasNextLine()) {
            String line = scan.nextLine();
            ArrayList<String> lineList = new ArrayList<>(Arrays.asList(line.split(";")));
            lst.add(lineList);
        }
        return lst;
    }
}
