import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Shelf shelf = new Shelf();
    Scanner scnr = new Scanner(System.in);

    String greeter_message = "";

    System.out.print("Chose the language:\nRU or EN: ");
    String option = scnr.nextLine().toUpperCase();

    switch(option){
      case "RU": 
        shelf.setRussian();
        break;

      case "EN":
        break;

      default:
        System.err.printf("Invalid option: %s", option);
        scnr.close();
        System.exit(1);
    } 

    shelf.initiateAlphabet();

    if(shelf.russian){
      greeter_message = "В Вавилонской Библиотеке можно найти любую информацию, но это потребует времени. Какое слово вам нужно найти?\nВведите слово: ";
    }
    else{
      greeter_message = "In the Library of Babel you can find any information, but it would take some time. What word are you seeking?\nEnter the word: ";
    }

    System.out.print(greeter_message);
    String query = scnr.nextLine().toLowerCase();
    shelf.setQuery(query);
    scnr.close();
    shelf.findQuery();   
  } 
}
