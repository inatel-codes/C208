/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package as_mic;

import java.util.ArrayList;

/**
 *
 * @author Alexander
 */
public class Memory {
    ArrayList<String> intructions = new ArrayList<String>(); // Pedaço da memória para armazenar as instruções
    Registers registers = new Registers(); // Pedaço da memória para armazenar os registradores 

    public Memory() {
        // Instruções iniciais (A gente que escolheu)
        intructions.add("00010111000000000100000001000000"); // somai AS0, AS1, 64  - 74
        intructions.add("00000000000010000100010000100010"); // mult AS1, AS1, AS2 - 50
        intructions.add("00000000000000000000001000010001"); // soma AS0, AS0, AS1 - 124
        intructions.add("00010011000100001100000000010000"); // multi AS2, AS3, 16 - 48
    }
}
