package as_mic;

import java.util.ArrayList;

/**
 * - Classe MainMemory - A classe MainMemory cria a memória da Arquitetura
 * AS-MIC, armazenando as instruções a serem executadas.
 *
 * A arquitetura possui o registrador PC (Contador de Programa), que é
 * responsável por indicar a róxima instrução a ser executada.
 *
 */
public class MainMemory {

    // Memória Principal
    String[] mainMemory = new String[15];

    // "Busca os dados" da memória secundária
    public MainMemory() {
        // Instruções iniciais (A gente que escolheu)
        mainMemory[0] = "00010111000000000100000001000000"; // somai AS0, AS1, 64 
        mainMemory[1] = "00000000000010000100010000100010"; // mult AS1, AS1, AS2 
        mainMemory[2] = "00000000000000000000001000010001"; // soma AS0, AS0, AS1 
        mainMemory[3] = "00010011000100001100000000010000"; // multi AS2, AS3, 16 
        mainMemory[4] = "00100101000000000100000000000100"; // load AS0, AS1, 4
        mainMemory[5] = "00100111000000000100000000000100"; // store AS0, AS1, 4
        

    }
}
