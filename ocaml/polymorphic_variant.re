open Printf;

type number = [ | `Float(float) | `Int(int)];

type number_ordinal =
  | Float(float)
  | Int(int);

/** f: [< `Float of Float | `Int of int] -> float **/

let float_of_number =
  fun
  | `Int(x) => float(x)
  | `Float(x) => x;

let float_of_number2 =
  fun
  | Int(x) => float(x)
  | Float(x) => x;

let () = {
  printf("%f\n") @@ float_of_number(`Int(10));
  printf("%f\n") @@ float_of_number(`Float(0.3333));
  printf("%f\n") @@ float_of_number2(Int(10));
  printf("%f\n") @@ float_of_number2(Float(2.3));
};
