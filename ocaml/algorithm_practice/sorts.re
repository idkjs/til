let l = [8, 7, 2, 4, 6, 9, 3, 5, 1];

let print_list = xs => {
  print_string("[");
  print_string(List.map(string_of_int, xs) |> String.concat(" "));
  print_string("]\n");
};

/* buble sort O(n^2) */
let rec bubble_sort = l => {
  let rec walk =
    fun
    | [x, y, ...xs] when x > y => [y, ...walk([x, ...xs])]
    | [x, ...xs] => [x, ...walk(xs)]
    | xs => xs;

  let l' = walk(l);
  /* if same as previous, then return */
  if (l != l') {
    bubble_sort(l');
  } else {
    l;
  };
};

/* selection sort O(n^2) */
let rec selection_sort =
  fun
  | [] => []
  | [x, ...xs] => {
      let rec select_r = (min', out) => (
        fun
        | [] => [min', ...selection_sort(out)]
        | [x, ...xs] when x < min' => select_r(x, [min', ...out], xs)
        | [x, ...xs] => select_r(min', [x, ...out], xs)
      );

      select_r(x, [], xs);
    };

/* insertion sort O(n^2) */
let rec insertion_sort = l => {
  let rec insert = (x, l') =>
    switch (l') {
    | [] => [x]
    | [y, ...ys] =>
      if (x < y) {
        [x, y, ...ys];
      } else {
        [y, ...insert(x, ys)];
      }
    };

  switch (l) {
  | [] => []
  | [x, ...xs] => insert(x, insertion_sort(xs))
  };
};

let () = {
  print_list @@ bubble_sort(l);
  print_list @@ selection_sort(l);
  print_list @@ insertion_sort(l);
};
