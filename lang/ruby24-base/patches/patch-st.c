$NetBSD$

upstream [Backport #14073]

--- st.c.orig	2016-12-21 11:20:02.000000000 +0000
+++ st.c
@@ -1182,6 +1182,8 @@ st_insert2(st_table *tab, st_data_t key,
     if (tab->bins == NULL) {
         bin = find_entry(tab, hash_value, key);
 	new_p = bin == UNDEFINED_ENTRY_IND;
+	if (new_p)
+	    tab->num_entries++;
 	bin_ind = UNDEFINED_BIN_IND;
     } else {
         bin = find_table_bin_ptr_and_reserve(tab, &hash_value,
