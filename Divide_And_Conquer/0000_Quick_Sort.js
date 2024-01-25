function hoarePartition(arr, low, high) {
  const pivot = arr[low];
  let i = low - 1;
  let j = high + 1;
  while (true) {
    do {
      i++;
    } while (arr[i] < pivot);
    do {
      j--;
    } while (arr[j] > pivot);
    if (i >= j) {
      return j;
    }
    // Swap arr[i] and arr[j]
    [arr[i], arr[j]] = [arr[j], arr[i]];
  }
}

function quickSort(arr, low, high) {
  if (low < high) {
    const partitionIndex = hoarePartition(arr, low, high);

    quickSort(arr, low, partitionIndex);
    quickSort(arr, partitionIndex + 1, high);
  }
}
