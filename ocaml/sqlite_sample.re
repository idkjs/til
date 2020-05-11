open Core;
open Sqlite3;

let db_exec = (db, query) =>
  ignore @@ Sqlite3.exec_not_null_no_headers(db, _ => (), query);

let () = {
  let db = Sqlite3.db_open("./sqlite_sample.db");
  db_exec(db, "DROP TABLE sample_table");
  db_exec(
    db,
    "CREATE TABLE sample_table(id INTEGER UNIQUE NOT NULL, name TEXT)",
  );
  db_exec(db, "INSERT INTO sample_table values(1, \"Bob\")");
  db_exec(db, "INSERT INTO sample_table values(2, \"Alice\")");
  ignore @@
  Sqlite3.exec_not_null(
    db,
    ~cb=
      (row, header) =>
        Array.iter2_exn(row, header, ~f=(row, header) =>
          printf("Header: %s\nRow: %s", header, row)
        ),
    "INSERT INTO sample_table values(3, \"Sam\")",
  );
  ignore @@
  Sqlite3.exec_not_null(
    db,
    ~cb=
      (row, header) =>
        Array.iter2_exn(row, header, ~f=(row, header) =>
          printf("Header: %s\nRow: %s\n", header, row)
        ),
    "SELECT * FROM sample_table",
  );
  let result = ref([||]);
  let headers = ref([||]);
  ignore(
    Sqlite3.exec_not_null(
      db,
      (row, header) => {
                          result := Array.append(result^, row);
                          headers := Array.append(headers^, header);
                        } /* Array.iter row ~f:(fun e -> printf "%s: \n" e); */,
      "select * from sample_table",
    ),
  );
  ignore @@ Sqlite3.db_close(db);
  printf("Results\n");
  Array.iter(result^, ~f=e => printf("%s\n", e));
  printf("Header ");
  printf("%s\n") @@ headers^[0];
};
