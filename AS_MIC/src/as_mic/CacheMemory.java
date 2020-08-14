/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package as_mic;

/**
 *
 * @author Alexander
 */
public class CacheMemory {
    public int tag;
    public String data;
    public boolean valid = false;
    
    String[]cache = new String[4];
    
    public  boolean isValid(){
        for(int i=0; i<cache.length; i++){
            if(cache[i] != null)
            {
                this.valid = true;
                break;
            }       
        }
        
        return valid;
    }
    
    public void getDataForMainMemory(MainMemory mainMemory){
        System.out.println("Buscando da memória principal...");
        for(int i=0; i<cache.length; i++){
            cache[i] = mainMemory.mainMemory[(tag-4)+i];
        }
    }
}
