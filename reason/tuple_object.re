/* tuple (object) */
/* named */
type person = {
  name: string,
  age: int,
};

/* unnamed */
type two_strings = (string, string);

let print_person = person' => {
  Printf.printf("name: %s\n", person'.name);
  Printf.printf("age: %d\n", person'.age);
};

let print_two_strings = (two_strings': two_strings) => {
  let (a, b) = two_strings';
  Printf.printf("%s, %s\n", a, b);
};

let () = {
  let joseph = {name: "Joseph Cooper", age: 34};
  Printf.printf("name: %s\n", joseph.name);
  Printf.printf("age: %d\n", joseph.age);
  let amelia = {name: "Amelia Brand", age: 28};
  print_person(amelia);
  print_two_strings(("A", "B"));
  let (one, two) = ("one", "two");
  Printf.printf("%s\n", one);
  Printf.printf("%s\n", two);
};
