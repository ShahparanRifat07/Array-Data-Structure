#include <stdio.h>

int arr[100];
int size = 100;
int length=0;

void init() {
    length = 0;
}

void print() {
    for(int i=0; i<length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int is_full() {
    // checking if the length of the array is bigger or equal of the size of the array
    if(length>=size){
    	//if length is bigger or equal then return 1;
    	return 1;
	}
	//if length is not bigger or equal then return 0;
	return 0;
}

int is_empty() {
    // checking if the length of the array is less then or equal 0
    if(length<=0){
    	//if the condition is true then return 1
    	return 1;
	}
	//if the conditon is not true then return 0;
	return 0;
}

int insert_first(int item) {
    // checking if the length is smaller array size
    if(length<size){
    	// shifting all the elements of array in 1 position right 
    	for(int i=length-1;i>=0;i--){
    		//assigning the value of present index to their next index
    		arr[i+1]=arr[i];
		}
		// after executed the for loop all the elements are now shifted one position right and the 0 no index position value is now empty(garbage value)
		// now assigning the item in the first position of the array
		arr[0]=item;
		//incremant the length by 1
		length++;
		//if the condition is successgul then return 1;
		return 1;
	}
	//if the condition is not successgul then return 0;
	return 0;
}

int insert_last(int item) {
    // checking if the length is smaller array size
    if(length<size){
    	// assigning the item in the last index+1 position
    	arr[length]=item;
    	// incremant the length by 1
    	length++;
    	//if the condition is successgul then return 1;
    	return 1;
	}
	//if the condition is not successgul then return 0;
	return 0;
}

int insert_at(int item, int pos) {
    // checking if the length is smaller array size
    if(length<size){
    	//this for loop start from the postion index to the last index of the array
    	//and shifting the elements 1 index to the right
    	for(int i=length-1;i>=pos;i--){
    		//assigning the value of present index to their next index till i is equal to postion
    		arr[i+1]=arr[i];
		}
		//after executed the for loop the elements are now shifted one position right and the pos index value is now empty(garbage value)
		//  assigning the item in the pos index of the array
		arr[pos]=item;
		//incremant the length by 1
		length++;
		//if the condition is successgul then return 1;
		return 1;
	}
	//if the condition is not successgul then return 0;
	return 0;
}

int search(int item) {
    // this for loop will loop through all the elements from first to last of the array
    for(int i=0;i<length;i++){
    	// checking if the item is in the array by comparing every elements
    	if(arr[i]==item){
    		//if the item found then the loop will break and return the index number and exit the function
    		return i;
		}
	}
	//if the item not found in the loop then it will return -1 and exit the function
	return -1;
}

int search_from_back(int item) {
    // this for loop will loop through all the elements from last to first of the array
    for(int i=length-1;i>=0;i--){
    	// checking if the item is in the array by comparing every elements
    	if(arr[i]==item){
    		//if the item found then the loop will break and return the index number and exit the function
    		return i;
		}
	}
	//if the item not found in the loop then it will return -1 and exit the function
	return -1;
}

int remove_first() {
    /* first checking is this array is empty.
    if not then the if block will execute*/
    if(is_empty()==0){
    	//looping through all the elements of the array
    	for(int i=0;i<length;i++){
    		//shifting all the array element 1 position to the left so that the first element of the array will be replace its next element
    		arr[i]=arr[i+1];
		}
		//now reducing the array lenght 1 because of the first element is now gone but the array length is still the same;
		length--;
		// if the block is successful then it will return 1 and exit the function
    	return 1;
	}
	// if the block is not successful then it will return 0 and exit the function
	return 0;
}

int remove_last() {
    // checking is the array empty or not
    if(is_empty()==0){
    	//removing the last index of the array by decresing length by 1
    	length--;
    	//then return 1 if the block is successful
    	return 1;
	}
	//return 0 if the array is empty and the if codition is not excuted
	return 0;
}

int remove_at(int pos) {
    // first checking is the array is empty and the given position is bigger or equal to 0 and the position is less then array length
    if(is_empty()==0 && pos>=0 && pos<length){
    	//loop through all the elements from the position index to the last index of the array
    	for(int i=pos;i<length;i++){
    		//shiffting one index to the right from the position index to the last index
    		arr[i]=arr[i+1];
		}
		//decresing length by one
		length--;
		//if the block is successful then return 1
		return 1;
	}
	//if the block is not successful then return 0
	return 0;
}

int remove_item_first(int item) {
    // searching the index of the item by the search() fuction which will return the first index of the searched item then storing the index in a variable
    int index=search(item);
    //the remove the value of the index by calling the reomve_at() function
    remove_at(index);
}

int remove_item_last(int item) {
    // searching the index of the item by the search_from_back() fuction which will return the last index of the searched item then storing the index in a variable
    int index=search_from_back(item);
    //the remove the value of the index by calling the reomve_at() function
    remove_at(index);
}

int remove_item_all(int item) {
    // intializing another array for storing the indexes
    int dup[100];
    //intial length of the array is 0
    int l=0;
    //searching the item in the array by using search function, if the item is the function then this if block will execute
    if(search(item)>-1){
    	//loop through all the elements of the array
    	for(int i=0;i<length;i++){
    		//if the elements of the array is equal to the item then this block will execute
    		if(arr[i]==item){
    			//storing all the indexes of the elements that is matched with the item value
    			dup[l]=i;
    			//incresing the length of the dup array by 1
    			l++;
			}
		}
		//loop through all the elements of the dup[] array
    	for(int i=0;i<l;i++){
//    		printf("%d ",dup[i]);

			//removing the elements of the arr[] array by calling the remove_at function
			//it will remove all the indexes that were stored in the dup[] array
			//everytime removing one index the dup[] array elements value will decrese by 1 beacuse of remove_at() fuction will shift the elements position by 1 to the left
    		remove_at(dup[i]-i);
		}
//		printf("\n");
		//if the block is successful then return 1
		return 1;
	}
	//if the block is not successful then return 0
	return 0;
}

int replace(int old_item, int new_item) {
    // intializing another array for storing the indexes
    int dup[100];
    //intial length of the array is 0
    int l=0;
    //searching the item in the array by using search function, if the item is the function then this if block will execute
    if(search(old_item)>-1){
    	//loop through all the elements of the array
    	for(int i=0;i<length;i++){
    		//if the elements of the array is equal to the old_item then this block will execute
    		if(arr[i]==old_item){
    			//storing all the indexes of the elements that is matched with the old_item value
    			dup[l]=i;
    			//incresing the length of the dup array by 1
    			l++;
			}
		}
		
		////loop through all the elements of the arr[] array
		for(int i=0;i<length;i++){
			//loop through all the elements of the dup[] array
			for(int j=0;j<l;j++){
				//if the index of the arr[] array is equal to the dup[] array value then it will replace the value of the arr[] index with the new item value
				if(i==dup[j]){
					//assiging the new item value to the matched index
					arr[i]=new_item;
				}
			}
		}
		//if the block is successful then return 1
    	return 1;
	}
	//if the block is not successful then return 0
	return 0;
}

void clear() {
    // assiging the array length to 0 so that all items will be inaccessible
    length=0;
}


int main() {
	
    init(); // initializes the arraylist first
    
    // testing the functions here
	
	//is_empty() function test
	printf("Is array empty(1=empty,0=not empty) = %d \n",is_empty());
	
	//is_full() function test
	printf("Is array full(1=full,0=not full)=  %d \n",is_full());
	printf("\n");
	
	//insert_first() function test
	printf("Insert First Funtion test: \n");
    insert_first(10);
    insert_first(9);
    print();
    printf("\n");
    
    //is_full() function test
	printf("Is array full(1=full,0=not full)=  %d \n",is_full());
    
	//is_empty() function test
	printf("Is array empty(1=empty,0=not empty) = %d \n",is_empty());
	printf("\n");  
    
    //insert_last() function test
	printf("Insert last Funtion test: \n");    
    insert_last(1);
    insert_last(2);
    print();
    printf("\n");
	
	//insert_at() function test
	printf("Insert at Funtion test: \n");    
    insert_at(11,2);
    insert_at(6,0);
    insert_at(3,6);
    print();
    printf("\n");
    
    //search() function test
    printf("Search Function Test:\n");
    printf("Search: index= %d\n",search(3));
    printf("Search: index= %d\n",search(6));
    printf("Search: index= %d\n",search(7));
    printf("\n");
    
    
    
    //remove_first() function test
    printf("Remove First function test: \n");
    remove_first();
    print();
    printf("\n");
//    remove_first();
//    print();
//    remove_first();
//    print();
//    remove_first();
//    print();
//    remove_first();
//    print();
//    remove_first();
//    print();
//    remove_first();
//    print();
//    printf("Is array empty(1=empty,0=not empty) = %d \n",is_empty());


	//remove_last() function test
	printf("Remove Last function test\n");
	remove_last();
	print();
	printf("\n");
//	remove_last();
//	print();
//	remove_last();
//	print();
//	remove_last();
//	print();
//	remove_last();
//	print();
//	printf("%d \n",remove_last());
//	printf("%d \n",remove_last());
//	printf("Is array empty(1=empty,0=not empty) = %d \n",is_empty());



	//remove_at() function test
	printf("Remove at function test\n");
	insert_last(10);
	remove_at(2);
//	remove_at(0);
//	remove_at(4);
	print();
	printf("\n");
	
	
	//remove_item_first() function test
	printf("Remove item first function test\n");
	remove_item_first(10);
	print();
	printf("\n");
	
	
	//remove_item_last() function test
	printf("remove item last function test\n");
	insert_last(15);
	insert_last(13);
	insert_last(15);
	insert_last(2);
	insert_last(13);
	insert_last(13);
	insert_last(11);
	insert_last(21);
	print();
	remove_item_last(13);
	print();
	printf("\n");
	
	
	//remove_item_all() function test
	printf("Remove item all function test\n");
	remove_item_all(2);
	print();
	printf("\n");
	
	
	//replace() function test
	printf("Replace function test\n");
	replace(15,10);
	print();
	printf("\n");
	
	//clear() function test
	printf("Clear function test\n");
	clear();
//	printf(" %d\n",is_empty());
	print();
	
	
    return 0;
}
