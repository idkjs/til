type int_pair = (int, int);

let l = ((a, b): int_pair) =>
  switch (a, b) {
  | (a', b') when a + b > 10 => None
  | _ => Some((a, b))
  };

let () = {
  let (a, b) =
    switch (l((3, 5))) {
    | Some((a', b')) => (a', b')
    | None => (0, 0)
    };

  Printf.printf("%d\n", a);
  Printf.printf("%d\n", b);
};
