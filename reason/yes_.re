let rec yes_rec = word => {
  print_string @@ word ++ "\n";
  yes_rec(word);
};

let yes_while = word =>
  while (true) {
    print_string @@ word ++ "\n";
  };

let () =
  /* recursion is 10x faster */
  /* yes_while "y"; */
  yes_rec("y");
