let a = [|1, 2, 3|];

let () =
  Array.iter(
    fun
    | e => Printf.printf("%d\n", e),
    a,
  );
