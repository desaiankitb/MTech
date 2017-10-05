/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication2;

/**
 *
 * @author Admin
 */
public class Main {

    static int partition(int arr[], int left, int right) {

      int i = left, j = right;

      int tmp;

      int pivot = arr[(left + right) / 2];



      while (i <= j) {

            while (arr[i] < pivot)

                  i++;

            while (arr[j] > pivot)

                  j--;

            if (i <= j) {

                  tmp = arr[i];

                  arr[i] = arr[j];

                  arr[j] = tmp;

                  i++;

                  j--;

            }

      }



      return i;

}



static void quickSort(int arr[], int left, int right) {

      int index = partition(arr, left, right);

      if (left < index - 1)

            quickSort(arr, left, index - 1);

      if (index < right)

            quickSort(arr, index, right);

}
    public static void main(String[] args) {
        int A[] = {10, 15, 26, 12, 9, 8, 22};
          for(int j=0; j<A.length; j++)    // for each element,
         System.out.print(A[j] + " ");  // display it
        System.out.println("");

        quickSort(A,0,A.length-1);
         for(int j=0; j<A.length; j++)    // for each element,
         System.out.print(A[j] + " ");  // display it
        System.out.println("");
   
    }

}
