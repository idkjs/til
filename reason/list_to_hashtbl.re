open Core;

let l = [("b", 2), ("c", 3), ("a", 1)];

let () = {
  /* list to hashtbl */
  let table = Hashtbl.of_alist_exn((module String), l);
  /* hashtblはkeyでソートされる */
  Hashtbl.iter(table, data => printf("%d\n", data));
  /* hashtbl to list */
  /* hashtblのソート順とは逆で返ってくる */
  let l' = Hashtbl.to_alist(table);
  List.iter(l', ~f=((key, value)) =>
    printf("key: %s\nvalue: %d\n", key, value)
  );
};
