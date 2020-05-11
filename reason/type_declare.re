/* other name */
type integer = int;
type pair_of_ints = (int, int);

/* optional type */
type pair_of_ints_op =
  | None
  | Some(pair_of_ints);

type my_tuple = (string, string);

/* variant type */
/* それぞれがコンストラクタ、これらによって初期化された値が型`foo`を持つ */
/* enum */
type foo =
  | Type1
  | Type2
  | Type3;

type bar =
  | Nothing
  | Int(int)
  | Pair(int, int)
  | String(string)
  | Object({
      key: int,
      value: string,
    });

let () = {
  let n: integer = (10: integer);
  let _pair: pair_of_ints_op = (Some((3, 5)): pair_of_ints_op);
  let _type1: foo = (Type1: foo);
  /* _string typed `bar` */
  let _string: bar = (String("string foo"): bar);
  let _object: bar = (Object({key: 0, value: "first element"}): bar);
  /* inherit super class */
  Printf.printf("%d\n", n);
  let (tup_one, tup_two): my_tuple = ("string1", "string2");
  Printf.printf("%s\n", tup_one);
  Printf.printf("%s\n", tup_two);
};
