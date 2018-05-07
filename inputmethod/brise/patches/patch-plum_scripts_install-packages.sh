$NetBSD$

* prevent unwanted updating packages

--- plum/scripts/install-packages.sh.orig	2018-04-05 10:06:43.000000000 +0000
+++ plum/scripts/install-packages.sh
@@ -38,10 +38,10 @@ install_package() {
     else
         if [[ -z "${option_no_update}" ]]; then
             echo $(info 'Updating package:') $(highlight "${package}")
+            "${script_dir}"/update-package.sh "${package_dir}" "${branch}"
         else
             echo $(info 'Found package:') $(highlight "${package}")
         fi
-        "${script_dir}"/update-package.sh "${package_dir}" "${branch}"
     fi
     install_files_from_package "${package_dir}"
 }
