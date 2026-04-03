class DynamicArray {
private:
    int * myArray;
    int length;
    int capacity; 
public:
    
    DynamicArray(int capacity) : capacity(capacity), length(0) {
    if (capacity > 0){
        myArray = new int[capacity];
    }
      
    }

    int get(int i) {
        return myArray[i];
    
    }

    void set(int i, int n) {
     if (i >= 0 && i < length){
        myArray[i] = n;
     }
    }

    void pushback(int n) {
      
        if (length == capacity){   
        resize();
        
         }
        myArray[length] = n;
        length++;   
    }

    int popback() {
      if (length > 0){
    
      length--; 
      }
       return myArray[length];
    }

    void resize() {
       capacity = capacity * 2; 
       int *newArr = new int[capacity];
       for(int i = 0; i < length; i++){
        newArr[i] = myArray[i];
       }
       delete [] myArray; 
       myArray = newArr;
    
    }

    int getSize() {
         return length; 
    }

    int getCapacity() {
      return capacity; 
    }
};
