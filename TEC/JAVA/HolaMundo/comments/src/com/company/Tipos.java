package com.company;

public class Tipos {
    /**
     * @param args
     * Clase demostrativa de los diferentes tipos de variables que
     * existen en java
     */
    public static void main(String[] args) {
        // tipo idetificador = valor
        //tipo identificador; y luego identitificador=valor

        /** 
         * Tipos enteros por ejemplo
        */
        //enteros
        byte bnumber=1; //1 byte (8 bits)
        short snumber=2; //2 byte
        int inumber=3; //3 bytes
        long lnumber=4; //4 bytes

        //punto flotante
        float flot =4.9f; 
        double dob =9.99d;
        
        //caracter
        char caracter ='a';

        //booleanos
        boolean bool = true;

        //cadenas de texto
        String nombre ="Alex";

        //tipos envoltorio * pueden ser Null
        /* 
        Integer nNumber = null; //es int pero en mayuscula
        Long lNumber =null; //long mayuscula
        Boolean bBool=null; */

        System.out.println((bnumber+snumber+inumber+lnumber+flot));
        System.out.println(dob);
        System.out.println(caracter);
        System.out.println(bool);
        System.out.println(nombre);
        

    }
}
