let square_area = f =>
  switch (f) {
  | f when f < 0.0 => failwith("under 0")
  | f when f >= 0.0 => f ** 2.0
  | _ => failwith("other")
  };

let () = {
  let area = square_area(3.0);
  Printf.printf("%F\n", area);
  let area =
    try(square_area(-3.0)) {
    | _ =>
      Printf.printf("error");
      exit(1);
    };

  Printf.printf("%F\n", area);
};
