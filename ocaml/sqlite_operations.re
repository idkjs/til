open Core;
open Sqlite3;

let find_index = (~predicate, arr) => {
  let (index, _) =
    Array.findi_exn(~f=(index, value) => predicate(value), arr);
  index;
};

type row = array(string);
type column_name = string;
type db_result = (array(column_name), array(row));

let get_rows = (db, query_string): db_result => {
  let result = ref([||]);
  let columns = ref([||]);
  ignore @@
  Sqlite3.exec_not_null(
    db,
    (row, column) => {
      columns := column;
      result := Array.append(result^, [|row|]);
    },
    query_string,
  );
  (columns^, result^);
};

let get_values_by_column = (result: db_result, column) => {
  let (header, values) = result;
  let index = find_index(~predicate=v => String.equal(v, column), header);
  Array.map(~f=v => v[index], values);
};
