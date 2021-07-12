#include "hash.h"

//int size = 0;
#define maxi 100


hashtable* init()
{
    int i;
    hashtable *array= new hashtable[maxi];
    //array=(hashtable*)malloc(maxi*sizeof(hashtable));
   
    for (i = 0; i < maxi; i++)
    {
    //printf("hello %d",maxi);
	array[i].flag = 0;
	array[i].data.key=-1;
	//array[i].data.value="";
    }
    return array;
}

int hashcode(int key)
{
    return (key % maxi);
}

int insert(item x,hashtable *array)
{
    int key=x.key;
    int index = hashcode(key);
    int i = index;

    while (array[i].flag == 1)
    {
        if (array[i].data.key == key)
        {
            //printf("\n Key already exists, hence updating its value \n");
            //array[i].data->value = value;
            printf("Username already exists!!");
            return -1;
        }
        i = (i + 1) % maxi;
        if (i == index)
        {
            printf("\n Hash table is full, cannot insert any more item \n");
            return -1;
        }
    }
    array[i].flag = 1;
    array[i].data.key = x.key;
    array[i].data.value=x.value;
    //size++;
    printf("\n Key (%d) has been inserted \n", key);
}

 /*void remove_element(int key)
{
    int index = hashcode(key);
    int  i = index;

    while (array[i].flag != 0)
    {

	if (array[i].flag == 1  &&  array[i].data->key == key )
        {


		array[i].flag =  2;
		array[i].data = NULL;
		size--;
		printf("\n Key (%d) has been removed \n", key);
		return;

	}
	i = (i + 1) % maxi;
	if (i == index)
        {
		break;
	}

    }

    printf("\n This key does not exist \n");
}
*/

int display(hashtable* array)
{
    int i;
    for (i = 0; i < maxi; i++)
    {
        int key = array[i].data.key;
        if (key==-1)
        {
            //printf("\n Array[%d] has no elements \n", i);
            //return-1;
        }
        else
        {
            printf("\n Array[%d] has elements -: \n  %d (key) and %s(value) \n", i,key,array[i].data.value);
        }
    }
}

string find(int key,hashtable* array)
{
    int index = hashcode(key);
    int i = index;

    if(array[i].flag==0)
    {
        printf("\n** Invalid username **\n");
        return "";
    }

    while (array[i].flag == 1)
    {
        if (array[i].data.key == key)
        {
            return array[i].data.value;
        }
        i = (i + 1) % maxi;
        if (i == index)
        {
            //Not found
            printf("\n** Invalid username **\n");
            return "";
        }
    }

}


