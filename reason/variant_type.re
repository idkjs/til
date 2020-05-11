open Core;

/* enum */
type oneTwoThree =
  | One
  | Two
  | Three;

let one_two_three_to_int = x =>
  switch (x) {
  | One => 1
  | Two => 2
  | Three => 3
  };

let l: list(oneTwoThree) = (List.rev([One, Two, Three]): list(oneTwoThree));

/* 多相バリアント */

/** [> `On | `Off] list **/

let l' = [`On, `Off, `Number(10)];

let to_int =
  fun
  | `On => 1
  | `Off => 0
  | `Number(n) => n;

/** [< `Number of int | `Off | `On ] -> [> `Number of int | `Off | `On ] **/

let switch_ =
  fun
  | `On => `Off
  | `Off => `On
  | `Number(x) => `Number(- x);

let to_string =
  fun
  | `On => "On"
  | `Off => "Off"
  | `Number(n) => string_of_int(n);

let () = {
  List.iter(l, x => printf("%d\n") @@ one_two_three_to_int(x));
  List.iter(l', x => printf("%d\n") @@ to_int(x));
  List.iter(List.map(~f=switch_, l'), x => printf("%d\n") @@ to_int(x));
  List.iter(List.map(~f=to_string, l'), x => printf("%S\n", x));
};
