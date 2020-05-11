open Core;
open Re2;

let read_file = filepath => {
  let ic = In_channel.create(filepath);
  In_channel.input_all(ic);
};

/* ?????? */
let csv_split_pattern = "(?:^|,)(?=[^\"]|(\")?)\"?((?(1)[^\"]*|[^,\"]*))\"?(?=,|$)";

class csv (~header=true, ()) = {
  as self;
  val mutable all: list(string) = ([]: list(string));
  val mutable header = header;
  pub header_exit = b => header = b;
  pub read_csv = filepath => {
    let raw_csv = read_file(filepath);
    /* WIP */
    raw_csv;
  };
  pub get_header =
    if (header) {
      List.nth(all, 0);
    } else {
      failwith("header option is false");
    };
  pub get_body =
    if (header) {
      List.tl(all);
    } else {
      Some(all);
    };
  pub get_nth_row = n => List.nth(all, n);
};
