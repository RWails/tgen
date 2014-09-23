/*
 * See LICENSE for licensing information
 */

#ifndef SHD_TGEN_TRANSFER_H_
#define SHD_TGEN_TRANSFER_H_

typedef enum _TGenTransferType {
	TGEN_TYPE_NONE, TGEN_TYPE_GET, TGEN_TYPE_PUT,
} TGenTransferType;

typedef struct _TGenTransferStatus {
    guint64 bytesRead;
    guint64 bytesWritten;
} TGenTransferStatus;

typedef enum _TGenTransferEventFlags {
    TGEN_EVENT_NONE = 0,
    TGEN_EVENT_READ = 1 << 0,
    TGEN_EVENT_WRITE = 1 << 1,
    TGEN_EVENT_DONE = 1 << 2,
} TGenTransferEventFlags;

typedef struct _TGenTransferCommand {
    gsize id;
    TGenTransferType type;
    gsize size;
} TGenTransferCommand;

typedef struct _TGenTransfer TGenTransfer;

TGenTransfer* tgentransfer_new(gchar* commanderName, TGenTransferCommand* command);
void tgentransfer_ref(TGenTransfer* transfer);
void tgentransfer_unref(TGenTransfer* transfer);

TGenTransferEventFlags tgentransfer_onSocketEvent(TGenTransfer* transfer, gint socketD, TGenTransferEventFlags flags);

#endif /* SHD_TGEN_TRANSFER_H_ */
