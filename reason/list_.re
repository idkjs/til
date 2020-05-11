open Core;
open Printf;

/* initialize [0; 1; 2; 3; 4] */
let l1 = List.init(5, n => n);

/* initialize [5; 6; 7] */
let l2 = List.init(3, n => n + 5);

/* 1からnまでの奇数 */
let odd_list = n =>
  List.filter(n_ => n_ mod 2 != 0, List.init(n, n' => n' + 1));
let find_index = (l, ~predicate) => List;

let () = {
  List.iter(e => printf("%d ", e), l1);
  print_string("\n");
  List.iter(e => printf("%d ", e), l2);
  print_string("\n");
  /* append (like concat, but ocaml concat is like flatten) */
  let l3 = l1 @ l2;
  List.iter(e => printf("%d ", e), l3);
  print_string("\n");
  /* get nth element */
  printf("%d\n", List.nth(l1, 3));
  List.iter(e => printf("%d ", e), odd_list(11));
  print_string("\n");
};
