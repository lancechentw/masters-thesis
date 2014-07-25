int ProcessURL ( char * TheURL , char * Hostname , char * Filename , char * Actu
alFilename , unsigned * Port )
{
        char            BufferURL [ MAXLEN ] ;
        char            NormalURL [ MAXLEN ] ;
        int             I ;
        
        /* clear everything. Is this necessary? not sure */
        memset ( Hostname , '\0' , strlen ( TheURL ) ) ;
        memset ( Filename , '\0' , strlen ( TheURL ) ) ;
        memset ( ActualFilename , '\0' , strlen ( TheURL ) ) ;
        /* remove "http://" */
        strcpy ( BufferURL , TheURL ) ;
        /* BUGFIX: strlwr ( BufferURL )? */
        if ( strncmp ( BufferURL , "http://" , 7 ) == 0 )
        {
...
