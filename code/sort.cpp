sort(begin, end, [cmp]);
min_element(begin, end, [cmp]);
max_element(begin, end, [cmp]);
nth_elemnt(begin, begin + nth, end, [cmp]); // put nth in place
random_shuffle(begin, end);
unique(begin, end); // place les doublons à la fin si trié
lower_bound(begin, end, val); // premier >= val si trié
upper_bound(begin, end, val); // premier > val si trié
