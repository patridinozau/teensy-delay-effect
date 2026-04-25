// include java.util.*
// List<Integer> list=Arrays.asList(10,4,-1,5);
// int[] array={6,-4,12,0,10};
// Collections.sort(list);
// Integer converted[] = list.toArray(new Integer[4]);
// System.out.println(converted[0]);
// System.out.println(Arrays.binarySearch(array, 12));

public class Snake{}
public class Cobra extends Snake {}
public class GardenSnake extends Cobra {}
public class SnakeHandler{
    private Snake snake;
    public void setSnake(Snake snake) {this.snake=snake;}
    public static void main (String[] args){
        new SnakeHandler().setSnake(new GardenSnake());
    }
}