import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Stephanie on 2/27/15.
 */
public class FileReader {
    Scanner s = new Scanner(Paths.get("hallways.txt"));
    List<Integer> integers = new ArrayList<>();

    while (s.next()) {
        if (s.hasNextInt()) {
            integers.add(s.nextInt());
        } else {
            s.next();
        }
    }

}
