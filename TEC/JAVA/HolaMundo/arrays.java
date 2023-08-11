import java.util.Random;

public class ArrayClase {
    public static void main(String[] args) {

        //Arreglo de enteros con numeros random, de tamano 10
        /*int[] myList = new int[10];
        for (int i = 0; i <=9; i++){
            Random random = new Random();
            myList[i]=random.nextInt(100);
        }
        for (int i = 0; i <= 9; i++){
            System.out.println(myList[i]);
        }
        //el 11 elemento no se puede insertar, fuera del tamano

        //matriz de 10x15 con numeros randoms
        int[][] myMatrix = new int[10][15];
        for (int i = 0; i <=9; i++){
            for (int j = 0; j <=14; j++){
                Random random = new Random();
                myMatrix[i][j]=random.nextInt(100);
            }
        }
        for (int i = 0; i <=9; i++){
            String fila="[";
            for (int j = 0; j <=14; j++){
                fila+=myMatrix[i][j]+",";
            }
            System.out.println(fila+"]");
        }*/
        //Declare un arreglo  de 5 DIMENSIONES. asignado en random e imprimalo
        int[][][][][] myArreglo5D = new int[3][3][3][3][3];
        for (int i = 0; i <=2; i++){
            for (int j = 0; j <=2; j++){
                for (int k = 0; k <=2; k++){
                    for (int l = 0; l <=2; l++){
                        for (int m = 0; m <=2; m++){
                                Random random = new Random();
                                myArreglo5D[i][j][k][l][m]=random.nextInt(100);
                        }
                    }
                }
            }
        }
        for (int i = 0; i <=2; i++){
            for (int j = 0; j <=2; j++){
                for (int k = 0; k <=2; k++){
                    for (int l = 0; l <=2; l++){
                        for (int m = 0; m <=2; m++){
                            System.out.println(myArreglo5D[i][j][k][l][m]);
                        }
                    }
                }
            }
        }

    }
}
