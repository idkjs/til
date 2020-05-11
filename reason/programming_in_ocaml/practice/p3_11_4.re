let max_ascii = s => {
  let n = String.length(s);
  let rec iter = ((max_char, i)) =>
    if (i == n) {
      char_of_int(max_char);
    } else {
      iter((max(max_char, int_of_char(s.[i])), i + 1));
    };

  iter((0, 0));
};

let () = Printf.printf("%c\n", max_ascii("string"));
