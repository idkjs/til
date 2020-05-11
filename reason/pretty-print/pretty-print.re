open Printf;
open String;

/* TODO: change display style if has many elements */
let string_of_array = arr => "[" ++ concat("; ", arr) ++ "]";

type printable =
  | Int(int)
  | Float(float)
  | String(string)
  | StringList(list(string))
  | IntList(list(int))
  | FloatList(list(float));

class wrapper = {
  as self;
  pub print = printf("%s\n");
};
