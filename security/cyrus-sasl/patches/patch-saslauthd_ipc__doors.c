$NetBSD: patch-saslauthd_ipc__doors.c,v 1.1 2016/09/11 06:11:15 richard Exp $

match do_request() implementation signature to declaration

--- saslauthd/ipc_doors.c.orig	2012-01-27 23:31:36.000000000 +0000
+++ saslauthd/ipc_doors.c
@@ -209,7 +209,7 @@ void ipc_cleanup() {
  * do_auth() back in saslauthd-main.c, then send the 
  * result back through the door.
  **************************************************************/
-void do_request(void *cookie, char *data, size_t datasize, door_desc_t *dp, size_t ndesc) {
+void do_request(void *cookie, char *data, size_t datasize, door_desc_t *dp, uint_t ndesc) {
 	unsigned short		count = 0;                 /* input/output data byte count           */
 	char			*response = NULL;          /* response to send to the client         */
 	char			response_buff[1024];       /* temporary response buffer              */
