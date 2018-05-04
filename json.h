#define	Jread(desc, src, dst)	((desc).type->read ? (desc).type->read((desc).ctx, (desc).size, (char*)(dst) + (desc).off, src) : -1)
#define	Jwrite(desc, dst, src)	((desc).type->write ? (desc).type->write((desc).ctx, (desc).size, (char*)(src) + (desc).off, dst) : -1)
#define	Jfree(desc, mem)	if ((desc).type->free) (desc).type->free((desc).ctx, (desc).size, (char*)(mem) + (desc).off)

typedef	int	Jrw(const void *ctx, ulong size, void *mem, Biobufhdr *bf);
typedef	void	Jfree(const void *ctx, ulong size, void *mem);
typedef	struct Jtype	Jtype;
typedef	struct Jdesc	Jdesc;
typedef	struct Jctxpair	Jctxpair;

struct	Jtype {
	Jrw	*read;
	Jrw	*write;
	Jfree	*free;
};

struct	Jdesc {
	const Jtype	*type;
	const void	*ctx;
	ulong	off;
	ulong	size;
};

struct	Jctxpair {
	const char	*name;
	Jdesc	desc;
};

extern const Jtype	jstruct;
extern const Jtype	jarray;
extern const Jtype	jmarray;
extern const Jtype	jlist;
extern const Jtype	jdouble;
extern const Jtype	jstring;
extern const Jtype	jmstring;
