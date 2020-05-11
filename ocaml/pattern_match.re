open Printf;

let t = [6, 2, 3, 4, 5];
let words = ["one", "two", "three"];

let nth = l =>
  switch (l) {
  | [] => 0
  | [x, ...xs] => x
  };

let is_empty_list = l =>
  switch (l) {
  | [] => true
  | _ => false
  };

/* or pattern */
/* redundant */
let _is_operater = c =>
  switch (c) {
  | '+'
  | '-'
  | '*'
  | '/' => true
  | _ => false
  };

/* good */
let is_operater =
  fun
  | '+'
  | '-'
  | '*'
  | '/' => true
  | _ => false;

/* returns last element 'a list -> 'a option */
let rec last =
  fun
  | [] => None
  | [x] => Some(x) /* if one element list */
  | [_, ...t] => last(t);

let () = {
  printf("%d\n", nth(t));
  printf("%b\n", is_empty_list(t));
  printf("%b\n", is_empty_list([]));
  printf("%b\n", is_operater('+'));
  let (a, b, c) =
    switch (["1", "2", "3"]) {
    | [a, b, ...c] => (a, b, c)
    | [a, ...b] => ("-1", a, b)
    | _ => ("-1", "-1", [])
    };

  printf("%S\n", a);
  printf("%S\n", b);
};
