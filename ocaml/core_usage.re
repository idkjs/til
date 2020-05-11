open Core;

let () = {
  let list_count_down = n => List.init(n, ~f=n' => abs(n' - n));
  let l = List.init(10, n => n);
  /* printfがCore直下に入っている */
  /* CoreではLabeled Argumentが多用されている */
  List.iter(l, ~f=n => printf("%d\n", n));
  List.iteri(list_count_down(12), ~f=(i, n) =>
    printf("%d番目: %d\n", i, n)
  );
  let str = String.strip("    xyz    ");
  printf("%S\n", str);
  let str_list = String.split("a b c d e f", ~on=' ');
  List.iter(str_list, ~f=s => printf("%S\n", s));
  printf("%S\n") @@ String.concat(~sep=?Some(", "), ["a", "b", "c"]);
};
