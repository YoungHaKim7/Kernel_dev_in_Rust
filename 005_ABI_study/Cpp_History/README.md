# (211129) 아르비드 노르베르그: C++ ABI의 발전
자동 더빙
SwedenCpp
- https://youtu.be/Uy_Ls-jQbR4?si=lueMRuza792nRBOE

<hr />

# 영문 스크랩

0:07
thank you that's working great uh hello my name is arvid
0:13
i'm going to talk about the c plus plus api and this is a little bit of a click bait
0:20
title i'm not actually going to introduce any novel ideas about how to evolve the
0:27
superfast api and also there isn't really a c plus plus abi what's that all about
0:34
um when this talk originally was scheduled um almost two years ago this was a very hot
0:40
topic in the superfast community and i guess i'm trying to keep it lukewarm or something
0:45
uh so this is gonna be a little bit of an introduction to uh like survey you might say of
0:51
uh what's going on in the simple class community right now so a little bit about myself i am primarily
0:56
involved in two projects my day job is at chia which is a brand new sort of sustainable blockchain
1:04
and also glub torrent which is a bittorrent implementation which is my night and weekends project
API and ABI
1:12
enough about that so real quick api and api what's that all about
1:18
so you could say that the api is sort of like the api but for the sort of zeros and ones of binaries
1:26
talking to each other uh versus source code talking to each other so things like uh
1:33
class layout uh or inline functions uh sort of affect
1:38
the api so you can see it a little bit like like this
1:44
these are two programs written by two separate organizations and they need to talk to each other
1:50
and in between they have the api to define this interface between them you could
1:56
you could sort of consider it a network protocol in that sense right they
2:04
they need to agree on on how to speak to each other and if if the api changes
2:09
then they won't work together anymore and that's a problem it's partly a problem because
2:16
the symptom of this happening is subtle memory corruption often in the best case it's a link error
2:24
uh so for instance if uh uh a and b have separate and independent
2:30
recycles uh you might want to be able to build independently or if a and b are closed source you might want to be able
2:36
to build them independently so so this problem uh actually happens uh quite a lot in in the wild here are a few
2:43
examples you might have say applications that accept various kinds of plugins instruments image filters
2:51
or python modules all of these things are built independently and then on the target
2:58
sort of production machine they need to work together
3:03
but perhaps more interestingly uh your application uh very often links
3:09
against the c plus plus standard library or some other system library and those are definitely built
3:16
pre-built like it's very rare that you build your own standard library but certainly system libraries
3:22
so the standard library sort of has a special place that it's sort of the root you know this problem exists in a lot of
3:28
places in the world but the standard library has like this problem
3:33
all the time and everyone is affected by it but right so any library that you any
3:39
pre-built library you link against it's important that the api that you agree on the api
3:46
for instance system packages that are installed on linux uh so let's
API issues
3:51
go through a little bit about the different places where api issues might
3:57
might happen or like where someone needs to decide what api to use so you have
4:02
the really low level calling conventions class layout uh
4:08
and alignment of types byte orders and things along those lines like the table layouts
4:14
and those are all decided by the operating system or the platform vendor so it might be like a combination of a
4:22
operating system and a vendor building it you have system calls into the kernel
4:29
right those are often very primitive but you still have some calling convention of you know where do you pass parameters
4:35
which registers do you use and system libraries
4:40
so think things like win32.dll or ld.so like the systems on shard libraries that
4:47
you need to link against uh the the api for those are also
4:52
controlled by the the platform vendor then you have the standard library types
4:58
so things like stud string stud vector uh the api of those
5:04
uh partly are influenced right by the low level class layout but they also have their own
5:10
actual implementation of their own layout so that's controlled by the compiler
5:17
and platform vendor together so because when you have a platform you often set those in stone
5:23
and then you have your library and you are responsible for that uh what i'm gonna
5:29
uh one thing to note here is that this the sip of standard committee is never in the owner column here the standard
5:37
doesn't specify an api uh the abi is the sort of practical concerns of
5:42
implementers and everyone using simple fast in practice um
5:48
but this is the this is the sort of main topic where the standard and sort of practic the
5:54
practical application of it meets so that's what i'm going to talk about
Inline namespaces
6:01
just to start off with an example to get on the same page imagine have a
6:07
function that takes us to the string as an argument uh the caller and the call you need to
6:12
agree on what that string looks like for instance does it look like this where you have a pointer to the string and
6:18
then you have a size of the string and then the capacitor of that allocation or is it perhaps the other way around that
6:24
you first have capacity and then size and then the pointer or is it perhaps a union of a long string in a short
6:30
string so you can have a short string optimization string and if the caller of the function and the function itself
6:37
disagree on what kind of stud string what the string looks like you will have you know a bad experience
6:46
so in s11 something called inline namespaces was introduced as an attempt to sort of
6:51
mitigate these kinds of problems so inline names this is short is a way
6:58
to affect the linker name of a symbol without affecting the
7:04
sort of source code name of it so you can refer to stood string and under the hood you actually get
7:10
a stood string with a version number in it um so this
7:17
this lets the standard library uh export multiple versions of stud string and it also lets you
7:23
have a linker error if if your two components disagree on which which the string it is because now it's encoded in
7:29
the linker name so they will mismatch
7:36
here's an example of what that would look like how the function v takes the string when you compile it
7:42
you have that long name is the mangled name and
7:47
that uh part of the mangle name uh translates to stood colin colonel
7:52
underground undergo one which is uh in libsy plus plus the version number of
7:58
of basic string here's the problem though if you
8:03
create a class called foo and you put a stud string in it and then your function takes
8:09
a foo object the link your name no longer contains the version of that string
8:14
so now the the caller and the callee might again disagree on what's the string what
8:21
version of string you're talking about and you might get sad
8:27
memory corruption so this is uh so this is not really
8:33
feasible for for the standard library you can't really have with the confidence and upgrade to stood string
8:40
and use a new layout of it and just stick it in a new version things would still break in in practice
Problems with ABI
8:49
um so in terms of the c plus plus standard and the zip plus sort of ecosystem
8:55
uh let's talk a little bit about the kinds of problems that arise when people want to break apis or want to do things that
9:02
would break apis and i would say there are three kinds of api breaks there's the quality of
9:07
implementation where someone made an implementation decision at one point
9:13
to do something a certain way and then in the later someone discovers there's a much better way of doing this but now
9:19
we're sort of set already because everyone has built against this way this layout this kind of implementation so
9:26
changing it would you know break linking of these programs together another one which maybe is a little bit
9:32
obvious is api changes but sometimes the api changes that people are talking about are kind of
9:37
subtle and it's not entirely obvious that you're talking about api api changes uh but
9:43
uh obviously if you're changing the api the api will also change examples are uh i'll get to some examples later
9:49
actually but um if you're changing the the semantics of of types or classes for instance uh
9:56
you probably need a new name for them anyway and then the third category
10:02
which most people agree on our problems where implementers of standardized
10:10
types in summer library have made decisions that sort of prevent
10:16
advancing the standard itself because doing so would invalidate their implementation and their platform
10:22
wouldn't be able to to implement this new version of the standard without breaking everyone and understandably
10:27
people are hesitant to do that however
10:32
between when people are talking about abis sometimes these three categories are kind of conflated and the third
10:38
category is exaggerated by pulling in other kinds of abi problems
10:44
because number three is really a problem for the standard library or the standard itself
10:50
uh so let's talk about some examples of qoi or quality of implementation
10:55
um again this is not really something the standard committee has anything
11:02
or much to say about as long as it leaves implementation freedom to do things
11:09
efficiently so people but people are stuck right in platforms
11:14
and vendors are stuck in old decisions so things like the small string
11:20
optimization there are many different implementations of small strings optimizations some are
11:26
more efficient than others and it's hard to take an implementation and change it because then all of a sudden everyone
11:32
will break right and student order map is another example
11:37
that people have been talking about for instance google has an abseil node hashmap which
11:43
actually has the same api but is a lot more efficient supposedly i haven't tested it myself but that's what they
11:48
say implementation was to the hash
11:54
sharedpointer in the column convention of unique pointer that's an especially interesting
12:00
example where you need pointer being
12:05
a non-trivial type when you pass it you would think that it's just passed in a register as a plain pointer because it's
12:11
just a plain pointer but uh it's actually passed through memory because it needs to be distracted by the
12:17
by the caller so it's kind of an unfortunate uh
12:23
consequence of of the way apis are are defined right now where using unique pointer actually
12:29
incurs overhead over a plane pointer i'm optimistic that we'll be able to
12:34
solve it in the future but maybe it's going to be a while the next category are
API changes
12:41
api changes or maybe subtle api changes for instance uh if you would like to
12:47
have a small object optimization versus the vector which probably would be a good idea in very many cases
12:53
uh the the api of the vector doesn't allow this for perhaps subtle reasons
12:58
uh for instance the pointer and iterator stability guarantees would change because if you have
13:04
a small small vector optimized where the elements actually live inside the vector
13:09
object and you move it somewhere else the objects would move as well whereas today
13:15
the object would stay on the heap in the same place so the pointers are stable there are also exception guarantees
13:20
changes right if you actually if uh what if the move the move constructors show right
13:29
another example this is back to unordered set and onward map there are other implementations of
13:34
unordered sets where you use open addressing which also have
13:39
similar issues with pointer and iterator stability where they had objects have to be moved around
13:46
uh and also the map instead set sometimes you know you might want those
13:52
to be actual b3s to be more efficient but that doesn't support the current api
13:58
specification uh so now to the actual
14:03
problems uh i call them all of these are actual problems right but this is the from the
14:08
superfast standard point of view these are the sort of difficult problems
14:14
uh these are examples where
14:20
someone wants to make a change to the standard that appear to be api compatible but
14:25
for often subtle reasons cannot be implemented by one vendor
14:31
there's actually a paper called uh p 1656 that has some like a bit of a survey uh
14:38
of examples of this uh it's short if you're interested i would recommend reading it
14:45
uh yeah one one other thing the asterisk there
14:51
there are cases where compilers or compiler vendors can do dirty tricks or like compiler magic
14:59
to to preserve a compatibility even in cases where they otherwise wouldn't like they can
15:04
they can do tricks that you couldn't with your classes because they can treat them separately like for instance a compiler could
15:11
change the column convention for unique pointer by just knowing that we know what the unique pointer is we can just
15:16
pass this as a plain pointer yes this is the case for select like jbl api
15:23
attribute tries to uh i'm not 100
15:29
familiar with trivial api but yes the trivially buy is something very similar to like i think
15:35
you might be able to do it with triple api there are proposals to sort of standardize that
15:43
practice uh in in ways where you could make your own classes um
15:49
behave like that where you guarantee that uh the you know they don't need to be
15:54
distracted basically you can um
16:00
right so one one side example in my mind uh is
16:06
uh it would be nice if the map instead set could be no except move constructable
16:12
um the way visual studio implements map and set today they cannot be you know except not
16:18
constructed because every time you construct a new instance of stood mappers that said they actually need to
16:23
heap allocate a sentinel node for their map or set
16:30
uh even if you move from one that already exists the one you move out of still need to be
16:36
in a valid state so it still needs that empty node to indicate that it's empty
16:43
this is a an example where a scope lock
16:50
scope lock is a you know you take a mutex and and it locks that mutex and then at the end of the scope it releases
16:55
the mutex that there was a paper to extend that so that you could take any number of
17:01
locks or any number of mutexes by making it a variatic template
17:08
but at least one vendor had a name and mangling scheme where a variatic template of one was mangled
17:16
differently than than a regular template of one so that failed that had to change so the
17:21
name there's a new name for lock guard instead of scope lock that's one example of you know
17:27
the consequences of having this implemented and working
17:32
practically another really interesting example i think is in max t it had never occurred to me until
17:38
recently that inmax t is the widest integer available on your platform
17:45
which means that it will be encoded in the api and if anyone ever refers to intex t and then
17:52
in max t changes what it means things will break so we're kind of stuck now in max t can
17:58
only mean whatever it means right now if we ever get int 128
18:03
t then in max t will still have to mean whatever it means today to not break
18:12
so um although there is a light at the end of this tunnel or something like that
18:18
uh every time a platform goes through a major transition to a new architecture for instance
18:24
you have an opportunity to also revisit all of these api choices to change the calling convention of unique pointer for
18:30
instance or um change you know other things in max t for instance uh so when iphone
18:38
went from arm v7 to arm 64 for instance that's an example where everyone had to recompile everything anyway so you could
18:44
apple in fact i believe they did uh update some of the libc plus
18:50
sort of the api decisions another example is win32 to win 64. uh i
18:56
think the probably the most well-known a buyer decision or change they made was the exception handling they went we went
19:01
from uh sort of the what do you call that the sort of try
19:06
catch where you actually keep track of
19:12
catch handlers to the more common table based exception handling in win 64.
19:18
and also the mac recently made this transition from
19:23
x8664 to amd64 i don't know if they made any updates but i imagine they did
Solutions
19:32
um so what can be done about this um
19:38
one thing is all of these good ideas that people want to have could be implemented in libsy plus bus
19:45
or in other standard libraries but disabled by macros in fact lib superfast has this they have
19:51
at least on some other types they have alternative alternative implementations but you can pick
19:56
which one to use so whenever the next big architecture upgrade is coming you can then just you
20:03
know all this is already implemented you can just pick like switch to it and use that
20:08
um herbstopter proposed
20:15
a language feature where you could sort of have a portable api where you say you know we have the
20:22
whatever api or whatever implementation of the standard library we want to use for maximum performance
20:27
we have that but then you can also mark up something to say oh this is meant for interoperability so now like pick the
20:33
the the portable version of this so that we can talk to each other and then the other side can convert back to whatever
20:39
it wants so uh there's a paper that n 4028
20:44
another idea that have been floated is to have the loader and linker produce glue code
20:50
to convert types in and out sort of
20:55
a little bit like windows on windows 64 did when microsoft transitioned to
21:00
win64 uh they have blue code so that win32 application can still call system
21:06
make system calls uh and they get translated into 64-bit system calls
21:11
that's really limited even even the windows and windows 64 had its limitations and
21:18
uh if you're going to try to apply that to an arbitrary superplus api i think that's virtually impossible
21:26
uh there's another recent paper
21:32
um that if i understand it correctly is proposing that you can
21:38
mark up classes uh for for instance in the standard library to have
21:44
them have virtual interface wrappers be generated for them automatically so that you can sort of it's kind of similar to
21:50
the portable api except that you can pick the internal implementation
21:55
without a virtual interface but then when you're when you want interoperable operability
22:02
you pick the one with the virtual interface at the cost of performance that's p2123
22:09
from last year and i want to mention a few fun examples
Examples
22:16
of the real world what people have been doing in practice to
22:21
maintain a stable api so one thing obviously if you build
22:26
everything from source uh this doesn't really concern you very much uh but
22:33
uh especially if you also build a standard library if you don't build a standard library from source then you're still sort of locked into
22:39
to what it's using so but if you have a mono repo for instance where all of your dependencies
22:44
including the standard library maybe even the compiler is part of your dependency stream you can build up that
22:50
that's if you can do that that's a pretty nice uh way of
22:56
sweeping this problem under the carpet and pretending it doesn't exist but it's quite often that's not
23:02
practical uh i mentioned earlier plugins and python modules or programs accepting plugins from third
23:09
parties or really anytime you have closed source dependencies that you need to link against
23:17
so in minnesota two for instance this is an example of how uh one part of win32
23:24
protects itself for from future updates you have this structure and the first
23:30
field is the size and you're supposed to initialize that field with the size of your struct so you pass that in the
23:37
first thing the function can does is it looks what's the value what's the size of this track and then
23:42
it can know which struct you used right because maybe it can recognize a few newer versions or
23:48
older versions as well another example is com
23:54
i don't know if that's anyone has heard about that it's still around
24:00
where basically you turn all interfaces completely uh dynamic so you query an interface and
24:06
then you uh you know that can fail and uh it basically means that every object
24:12
can implement any number of interfaces basically you can have so it's similar to having
24:18
v tables or having a sort of virtual function interface
24:27
perhaps the most common is to use opaque types or pimple quantity implementation where you
24:34
simply make the layout an internal like an implementation detail the user of the
24:41
library or the the api only gets like a pointer to something it doesn't get to
24:46
see anything else and then you just operate on that pointer as long as all of the functions operating on the pointer are also sort of on the other
24:52
side of this this boundary it knows what kind of pointer it's talking about so an example is
24:59
f open f read f close and that family functions uh
25:04
never do actually look at that file pointer and like try to reference it and look what's inside there it's opaque
25:13
and this is probably my favorite uh if anyone was around in the bos times they actually used the c plus
25:20
api for their system libraries so they thought about this they
25:26
considered that they might want to add new virtual functions in the future to their class so they
25:31
just created a bunch of dummy v table entries and they also thought they might want
25:36
need to add new fields so they added you know some padding at the end so that they can grow their data fields into
25:45
uh it turned out that their main downfall was that it was all based on the gcc 295 api which was you
25:52
know terrible and you couldn't use in your compiler after that
25:58
all right lastly i wanna mention some tooling there are some pretty awesome tools uh
26:05
analyzing apis there's the abi compliance checker which is uh you know it's it's great for using a
26:13
in a ci uh make a dump of your first version of something and then
26:18
make sure that every ci build uh is compatible with that basically so you can make binary
26:25
releases uh and all of your users will will you know keep working
26:30
there's also the a by la laboratory which
26:36
scans a lot of open source libraries and gives you nice reports it looks something like this this i
26:43
think this is libsy plus plus probably so you see all the versions and then it gives you warnings and you can sort of
26:49
drill down and see what symbols changed and determine whether or not it's severe
26:55
enough so that's great that is the end of my presentation thank
Hashing
27:01
you
27:09
any questions yes you know this is suggesting to just
27:16
encode a type by all of its
27:28
yeah actually i was considering including that as well there's been a not a formal proposal but
27:35
some discussions on mailing lists about uh possibly just
27:40
hashing all of the types and make that sort of the name of the the mangle name or the link your
27:46
name for that class uh the problem is a lot of people rely on forward
27:52
declarations and all of a sudden that wouldn't work anymore because you can't function
27:58
because if you don't know the class you might get less
28:07
you can come up with tricks of like maybe you hash that string right too
28:17
yeah i mean symbols are hashed already like when you actually load the shared library i'm pretty sure that you don't
28:22
scan the list right it's it's a hash lookup to find the symbols also but
Python modules
28:31
yes python modules actually you mentioned what is the problem there or is a you know python enhancement
28:38
proposal regarding the real file generation and naming using many linux for instance and that's all the issue
28:44
it's like dealing with the with a very old compiler on a very old operating system yeah
28:51
you know right um
29:00
yeah i'm not an expert on python but right my understanding is that there's also this initiative to have an api
29:05
three uh sort of a stable python api between across all the python three versions and
29:12
these are two right to mitigate these problems uh but even in the manny linux example uh you're
29:19
kind of locking locking it down right to you just you say all of the linux distros you better use this one api you
29:26
better use this uh you know configuration of lipstick zip plus
29:31
because we still have problems with muscle-based distributions right
29:37
right so i don't think it solves the of the overarching problem but it's uh it's addressing it right
29:42
it's making things simpler for python
29:48
the problem is not the python the problems because as soon as you're not plugging all the dependencies into the same
29:55
process and the symbols are global so if you build the one plugin with gcc four
30:01
which had like old c pdi for standard streams and then you build another plugin with another api and you just use
30:08
it internally like the because before we had call strings now we have done no no code strings when you
30:14
load them into the same process you basically get a lot of ada problems because different versions of libraries
30:20
can come from different plugins into the same process then
30:26
all these dependencies should also be built using the same many linux
30:31
distribution i guess according to my understanding yeah just use c or just hide
30:50
right yes uh if you develop some open source library or something and it becomes
Documentation
30:56
popular but we have a tips for how do you document your api strategy for that
31:06
um yeah good question i don't have a great answer unfortunately i think my the convention that i've uh
31:14
embraced is to just have like whenever certain version numbers
31:19
tick up that's when i break api and and i think it's really difficult to never break api
31:26
basically because if you have a pro if you have something that has last lasted for 10 years like and you're stuck with your 10 year old
31:33
like mistakes like that's terrible you don't like yeah as long as your library is off the
31:38
source and you're saying
31:44
well but sometimes people take your library they make uh they make a package out of it and they
31:49
distribute it on a linux package manager and then somehow someone else links against it
31:55
and then you know you have to be careful if you ever want that package updated that other binaries alter the link against
32:02
you you need to preserve the encoder
32:10
but it's usually the same problem you have different libraries coming into the single process and they have different
32:16
dependencies like if you have library version ebay version one another api version two or they found
32:22
they cannot talk to each other and probably usually plug into it using cadi which is
Metadata
32:30
like a simple call on the data or in the interface basically right in api
32:38
is there any initiative to try to expand other metadata you provide
32:44
i mean kind of the basic problem is that the api doesn't come with
32:50
complete principle consumptions right yeah i mean in practice the
32:56
the symbol mangling does some of that right and you could imagine encoding more information in it
33:02
but the language as i mentioned with with the forward declarations of the type
33:09
you still need to be able to call a function that takes a pointer to foo without knowing what foo is and
33:15
that's a problem you know in the future when we don't have headers and no four declarations you know maybe we can move past that
33:36
yeah i think generating blue code to like translate code is going to be really uh
33:43
probably virtually impossible like my example that i'm thinking of is imagine you pass a
33:48
like a non-const reference of a twisted string to a function it spawns a thread and it updates this
33:55
to the string and then you synchronize through some other channel you might expect your string to update
34:00
if there was some translation there like when is that translation back happening
34:14
yeah i think i think that's the word of the goal that i think is you
34:19
know if we could at least get to there things would be much better yeah yeah
34:29
make the implementation but just mention c does the type of api standard either
34:36
boring that nothing happens there it doesn't change no no no no it's got next turn c which defines a very
34:42
statement rule you put your stuff behind the c it the implementation interface you want
34:48
and break stuff as long as the c interface to the public doesn't change but it just says that the c doesn't have
34:55
a standardized api either right in max t for instance is a problem in c as well for instance
35:03
but you have to say if you use the same c library i'm not sure about muscle but at
35:08
least with tulip c they guarantee this that older binary it will run still they use simple versioning for it and you can
35:16
run a binary from 50 years ago yes uh yes but stood string is complicated
35:24
yeah well that is c yeah i mean i mean they have two strings in in lipstick simple plastering right
35:30
they have the the traditional one the coping right and then they have the new small string optimized version
35:37
and you pick them with a macro and if if the two things you're linking to pick different ones it's not going to
35:43
work but you get linker errors so there's that i was specifically referring to the ck so okay
35:49
yeah i mean you can also see like basically the simpler the interface is the less likely you are to have problems with this you
35:55
can also have a c plus interface but pimple so that you hide all of the implementation details behind the
36:01
the laundry room so yeah if you only use pointers
36:06
yeah right but even if you use pointers it's a
36:13
problem like for example say under windows you might not necessarily use the same c library so you usually ship
36:19
it or you define which c library you use and then a free or malloc like you can't
36:24
monologue in one library and three in the other so there are quite some subtleties that you even have to take
36:29
into account when working with c so there is no api there either you just have to use the same c library and then
36:36
your kind are safe right there is windows at all they say used to see glasgow but
36:43
if you want to see it's just very recently that microsoft says oh we have now seen
36:48
yeah exactly here until then they said if you want to take this c part of the c blasphemous combined here is blasphemy
36:56
you don't have to see on windows at all true
37:02
i think this is not a good time to to change
37:11
[Applause]


<hr />

# 한글 번역(파파고 번역

- 잘 작동하고 있어요. 안녕하세요, 제 이름은 arvid0:13입니다. 저는 c 플러스 API에 대해 이야기하려고 합니다. 이는 약간의 클릭 미끼입니다. 0:20 title는 사실 0:27 초고속 API를 발전시키는 방법에 대한 새로운 아이디어를 소개하지 않을 것이며, 원래 이 강연이 예정되어 있던 0:34um에는 c 플러스 아비가 포함되지 않았습니다. 거의 2년 전에 이 강연은 초고속 커뮤니티에서 매우 뜨거운 0:40 topic가 되었고, 저는 이 주제를 미지근하게 유지하려고 노력 중입니다. 그래서 이 설문조사는 간단한 클래스 커뮤니티에서 현재 무슨 일이 일어나고 있는지 0:51 uh에 대해 조금 소개하는 내용이 될 것입니다. 그래서 저는 주로 두 프로젝트에서 0:56 involved로 일하고 있는데, 이는 새로운 종류의 지속 가능한 블록체인인 치아입니다. 1:04와 또한 저의 야간 및 주말 프로젝트인 글루브 토렌트 구현이기도 합니다API와 ABI1:12 정도면 정말 빠른 API와 API가 대략 1:18 정도라고 할 수 있습니다. 예를 들어, API는 API와 비슷하지만, 0과 1:26의 바이너리가 서로 대화하는 경우 uh1:33class 레이아웃 uh 또는 인라인 함수 uh와 같은 것들이 1:38에 영향을 미치기 때문에 이와 같은 현상을 볼 수 있습니다. 이 두 프로그램은 두 개의 별도 조직에서 작성한 것으로, 서로 대화해야 합니다. 1:50. 그리고 그들 사이에 이 인터페이스를 정의할 수 있는 API를 가지고 있습니다. 1:56은 네트워크 프로토콜이라고 할 수 있습니다. 그들은 서로 대화하는 방법에 대해 합의해야 합니다. 만약 API가 2:04로 변경된다면, 더 이상 함께 작동하지 않을 것입니다. 이는 부분적으로 문제입니다. 왜냐하면 2:16의 증상이 종종 미묘한 메모리 손상일 수 있기 때문입니다. 이는 최상의 경우 링크 오류입니다. 예를 들어, uh a와 b가 각각 독립적이고 독립적인 2:24 uh를 가지고 있다면 독립적으로 구축할 수 있을 것입니다. 또는 a와 b가 폐쇄된 소스라면 2:36이 독립적으로 구축할 수 있을 것입니다. 따라서 이 문제는 실제로 야생에서 꽤 많이 발생합니다. 예를 들어, 다양한 종류의 플러그인 기기 이미지 필터 2:51 또는 파이썬 모듈을 수용하는 애플리케이션이 있을 수도 있고, 그 다음에는 함께 작동해야 하는 생산 기계 2:58에 매우 자주 연결되지만, 더 흥미로운 점은 애플리케이션이 c 플러스 표준 라이브러리나 다른 시스템 라이브러리와 3:16을 함께 구축하는 것은 매우 드문 일이지만, 시스템 라이브러리 3:22와 같이 3:16에 미리 구축된 것들입니다. 따라서 표준 라이브러리는 전 세계 많은 3:28 곳에 이 문제가 존재한다는 것을 알고 있지만, 표준 라이브러리는 3:33과 같은 일종의 특별한 장소를 가지고 있습니다. 표준 라이브러리는 항상 이와 같은 문제를 가지고 있으며, 모든 사람들이 이 문제의 영향을 받습니다. 따라서 올바른 라이브러리를 제외한 모든 라이브러리는 3:39에 영향을 받습니다

- 3:39 사전 구축된 라이브러리와 링크하는 것은 중요합니다. 예를 들어, Linux에 설치된 시스템 패키지의 API 3:46에 동의하는 API는 플랫폼 공급업체가 4:52로 제어합니다. 따라서 API 문제가 발생할 수 있는 다양한 장소나 사용할 API를 결정해야 하는 장소에 대해 3:57로 넘어가 보겠습니다. 예를 들어, 4:02 정말 낮은 수준의 호출 규약 클래스 레이아웃 uh4:08과 테이블 레이아웃과 같은 줄을 따라 타입 바이트 순서가 정렬됩니다. 이는 모두 운영 체제나 플랫폼 공급업체에 의해 결정되므로 4:22 운영 체제와 시스템 호출이 커널 4:29로 구성된 벤더 빌딩의 조합처럼 매우 원시적인 경우가 많지만, 여전히 매개변수 4:35를 어디에 전달하는지 알고 있는 호출 규약이 있습니다. 따라서 win32와 같은 것들을 생각해 보세요. dll나 ld.so 같은 샤드 라이브러리 시스템에서 4:47로 링크해야 하는 API도 플랫폼 공급업체가 4:52로 제어합니다. 그러면 표준 라이브러리 타입 4:58로, stud string stud vector uh와 같은 것들은 부분적으로 낮은 수준의 클래스 레이아웃의 영향을 받지만, 컴파일러 5:17과 플랫폼 공급업체가 함께 제어할 수 있는 5:10 자체 레이아웃 구현도 있습니다. 따라서 플랫폼이 있을 때 종종 이를 stone5:23으로 설정하고 라이브러리가 있고 제가 5:29uh에 책임이 있기 때문에 여기서 주목해야 할 한 가지는 표준 위원회의 한 모금이 소유자 열에 포함되지 않는다는 것입니다. 여기서 doesn는 API를 지정하지 않습니다. abi는 5:42 implement 사용자와 간단한 빠른 시간을 사용하는 모든 사람들의 실질적인 관심사입니다. 하지만 이것이 표준 및 실용적인 5:54 practical 응용 프로그램과 일치하는 주요 주제입니다인라인 네임스페이스 6:01은 같은 페이지로 넘어가기 위한 예제로 시작하는 6:07 함수를 상상해 보세요. 이 함수는 우리를 문자열로 안내합니다. 예를 들어, 호출자와 호출자는 문자열의 모양에 대해 6:12로 동의해야 합니다. 예를 들어, 문자열에 대한 포인터가 있고 6:18로 그 다음에 해당 할당의 커패시터가 있는 것처럼 보이는가요? 아니면 그 반대로 6:24로 먼저 용량을 가지게 되고 나서 크기를 가지게 되는 건가요, 아니면 포인터가 짧은 6:30 문자열 내의 긴 문자열의 합집합인지에 따라 짧은 문자열 최적화 문자열을 가질 수 있습니다. 함수와 함수 자체의 호출자가 문자열이 어떤 종류의 스터드 문자열인지에 대해 6:37로 동의하지 않는 경우, 문자열이 어떤 종류의 스터드 문자열인지에 대해 6:46의 나쁜 경험을 하게 될 것입니다. 따라서 s11에서는 이러한 종류의 문제를 완화하기 위한 시도로 인라인 네임스페이스라는 것이 도입되었습니다. 따라서 이 짧은 인라인 네임스페이스는 기호의 링커 이름에 영향을 주지 않으면서도 7:04에 영향을 미치는 6:58의 방법입니다

- 6:58
심볼의 링커 이름에 영향을 주지 않고 영향을 미치기
7:04
그것의 소스 코드 이름 같은 것으로, 서 있는 문자열을 참조할 수 있습니다. 그리고 실제로 당신이 얻는 것은 후드 아래에 있습니다
7:10
버전 번호가 포함된 스탠드형 문자열은 다음과 같습니다
7:17
이것은 표준 라이브러리가 여러 버전의 스터드 문자열을 내보낼 수 있게 해주며, 또한 당신도 사용할 수 있게 해줍니다
7:23
두 구성 요소가 어느 문자열인지에 대해 일치하지 않는 경우 링커 오류가 발생합니다. 왜냐하면 이제 링커가 인코딩되었기 때문입니다
7:29
일치하지 않도록 링커 이름
7:36
다음은 문자열을 컴파일할 때 함수 v가 문자열을 가져오는 방식의 예입니다
7:42
당신은 그 긴 이름을 가지고 있습니다. 그것은 망친 이름입니다
7:47
망글 이름의 그 부분은 스탠딩 콜린 대령으로 번역됩니다
7:52
지하에서는 음, 음, 음, 음, 그리고 버전 번호를 더한 것을 겪습니다
7:58
기본 문자열의 문제는 다음과 같습니다
8:03
foo라는 클래스를 만들고 그 안에 스터드 문자열을 넣으면 함수가 다음과 같이 됩니다
8:09
foo 객체 링크에 더 이상 해당 문자열의 버전이 포함되지 않습니다
8:14
그래서 이제 발신자와 발신자가 문자열에 대해 다시 의견이 다를 수 있습니다
8:21
당신이 말하는 문자열의 버전이 슬플 수 있습니다
8:27
메모리 손상 때문에 이게 어, 그래서 이게 사실이 아닙니다
8:33
표준 라이브러리에서는 신뢰할 수 없고 스탠드 문자열로 업그레이드할 수 있습니다

- 8시 40분에 새로운 레이아웃을 사용하고 새 버전으로 붙이면 실제로는 문제가 발생할 수 있습니다. ABI8:49um의 문제에서는 여전히 문제가 발생합니다. 따라서 c 플러스 표준과 zip 플러스 생태계 측면에서 8시 55분에 사람들이 apis를 깨고 싶거나 9시 2분에 apis를 깨고 싶을 때 발생하는 문제의 종류에 대해 조금 이야기해 보겠습니다. 저는 9시 7분에 세 가지 종류의 api 브레이크가 있다고 말할 수 있습니다. 한 시점에서 누군가가 특정 방식으로 실행을 결정한 후 나중에 누군가가 이를 수행할 수 있는 훨씬 더 나은 방법이 있다는 것을 발견했지만, 지금은 9시 19분에 이미 어느 정도 해결된 상태입니다. 왜냐하면 9시 26분에 이와 같은 레이아웃을 변경하면 이 프로그램들을 서로 연결하는 것이 깨질 수 있기 때문입니다. 이는 api 변경 사항일 수도 있지만, 때때로 사람들이 말하는 api 변경 사항이 약간 9시 37분에 해당합니다. api 변경 사항에 대해 이야기하는 것이 완전히 명확하지는 않지만, 9시 43분에 api를 변경하는 경우 api도 변경될 것입니다. 예를 들어, api 유형이나 클래스의 의미를 변경하려면 api에 새로운 이름이 필요할 것입니다. 예를 들어, uh9:56 같은 유형이나 클래스의 의미를 변경하려면 새로운 이름이 필요할 수도 있습니다. 그리고 세 번째 카테고리 10:02는 여름 도서관에서 표준화된 10:10 유형의 구현자들이 표준 자체를 변경하는 것을 방지하는 결정을 내린 문제에 대해 대부분의 사람들이 동의합니다. 이는 표준화된 10:16을 변경하는 것이 그들의 구현과 플랫폼을 무효화할 수 있기 때문입니다. 10:22:27 사람들이 abis에 대해 이야기할 때 이 세 가지 카테고리가 때때로 혼동되기도 하고, 세 번째 10:38 카테고리가 표준 도서관이나 표준 자체에 실제로 문제이기 때문에 다른 종류의 qoi 문제 10:55um 또는 구현 품질의 예에 대해 이야기해 봅시다. 10:55um의 예에 대해 이야기해 봅시다 표준 위원회가 11:02나 그 이상 할 말이 없다는 것은, 사람들이 효율적으로 일을 할 수 있도록 구현의 자유를 남겨두기만 한다면, 11:09나 사람들은 플랫폼에 갇혀 있지만 공급업체들은 오래된 결정에 갇혀 있기 때문에 작은 문자열 11:20 최적화와 같은 여러 가지 작은 문자열 최적화 구현 방식이 있으며, 일부는 다른 구현 방식보다 11:26 더 효율적입니다. 그러면 갑자기 모든 사람들이 11:32가 오른쪽으로 넘어가고 학생 주문 지도가 또 다른 예로 11:37과 같은 예로 들 수 있습니다. 예를 들어, 구글에는 abseil 노드 해시맵이 있는데, 11:43 actually는 동일한 API를 가지고 있지만, 제가 직접 테스트해보지는 않았지만, 그들은 11:48 구현 방식이 해시에 적용되었다고 말합니다

- 11:48
구현이 해시에 적용되었다고 가정합니다
11:54
특히 흥미로운 고유 포인터의 열 규칙에서 공유 포인터
12:00
포인터가 필요한 예
12:05
trivial가 아닌 유형을 통과할 때는 레지스터에서 그냥 단순 포인터로 통과된 것처럼 생각할 수 있습니다
12:11
단순한 포인터일 뿐이지만, 실제로는 메모리를 통해 전달됩니다. 왜냐하면 그것은 주의를 분산시킬 필요가 있기 때문입니다
12:17
발신자에 의해 그래서 좀 안타깝네요
12:23
현재 고유 포인터를 실제로 사용하는 경우 아피스가 정의되는 방식의 결과
12:29
평면 포인터 위에 오버헤드가 발생합니다. 우리가 할 수 있을 거라고 낙관합니다
12:34
미래에 해결할 수 있지만 다음 카테고리는 시간이 좀 걸릴 수도 있습니다
API 변경 사항
12:41
API 변경 또는 미묘한 API 변경을 원하시면 예를 들어, uh
12:47
벡터에 비해 객체 최적화가 작은 경우가 많은데, 이는 아마도 매우 많은 경우에 좋은 아이디어일 것입니다
12:53
벡터의 API는 아마도 미묘한 이유로 이것을 허용하지 않습니다
12:58
예를 들어 포인터와 반복기의 안정성 보장이 변경되는 이유는 다음과 같습니다
13:04
요소들이 실제로 벡터 안에 있는 곳에 최적화된 작은 벡터
13:09
물체를 다른 곳으로 옮기면 물체도 움직이는 반면, 오늘날에는 물체도 움직입니다
13:15
객체는 동일한 위치에 힙에 머물기 때문에 포인터가 안정적입니다. 예외 보장도 있습니다
13:20
실제로 이동 생성자가 올바르게 표시되면 어떻게 될까요
13:29
또 다른 예는 순서가 없는 집합으로 돌아간 것이며, 이후 맵에는 다음과 같은 다른 구현이 있습니다
13:34
오픈 주소 지정을 사용하는 순서 없는 집합은 다음과 같습니다
13:39
포인터와 반복기의 안정성과 관련된 유사한 문제들은 객체를 이동시켜야 합니다
13:46
어, 그리고 지도를 대신 설정하면 원할 수도 있다는 것을 알 수 있습니다
13:52
더 효율적으로 만들기 위해 실제 b3가 되어야 하지만 현재 API를 지원하지 않습니다
13:58
사양 어, 그래서 이제 실제로
14:03
문제들은 모두 실제 문제들이라고 부르지만, 이것은 다음과 같습니다

- 14:08
초고속 표준 관점은 다음과 같은 어려운 문제들입니다
14:14
다음은 다음과 같은 예입니다
14:20
API 호환성이 있는 것처럼 보이는 표준을 변경하고 싶은 사람이 있습니다
14:25
종종 미묘한 이유로 한 공급업체가 구현할 수 없습니다
14:31
실제로 설문조사와 유사한 내용을 담은 논문이 있습니다
14:38
이 예시들은 짧습니다. 관심 있으시면 읽어보시길 추천합니다
14:45
어, 네, 또 하나는 별표입니다
14:51
컴파일러나 컴파일러 공급업체가 더티 트릭을 하거나 컴파일러 매직을 할 수 있는 경우가 있습니다
14:59
호환성을 유지하기 위해 다른 방법으로 원하지 않는 경우에도 호환성을 유지하기 위해
15:04
그들은 당신의 수업에서 할 수 없었던 트릭을 할 수 있습니다. 왜냐하면 컴파일러가 할 수 있는 것처럼 개별적으로 다룰 수 있기 때문입니다
15:11
고유 포인터에 대한 열 규칙을 변경하려면 고유 포인터가 무엇인지 알고 있어야 합니다
15:16
이것을 간단한 포인터로 전달합니다. 예를 들어, jbl API와 같은 선택의 경우입니다
15:23
속성 시도: 저는 100이 아닙니다
15:29
사소한 API에 익숙하지만, 네, 사소한 구매는 제가 생각하는 것과 매우 유사합니다
15:35
트리플 API로 할 수 있을지도 모릅니다. 표준화할 수 있는 제안들이 있습니다
15:43
자신만의 수업을 만들 수 있는 방법으로 연습하세요
15:49
그렇게 행동하세요, 당신이 알고 있는 것처럼, 그들이 그럴 필요가 없다는 것을 보장합니다
15:54
산만해서 기본적으로 음
16:00
그래서 제 마음속의 한 가지 측면 예는 어입니다
16:06
맵 세트 대신 이동 생성만 가능하면 좋겠습니다
16:12
오늘날 비주얼 스튜디오가 지도를 구현하고 설정하는 방식은 당신이 알지 못하는 것 외에는 알 수 없습니다
16:18
새로운 스탠드 매퍼 인스턴스를 구성할 때마다 실제로 필요하다고 말하는 스탠드 매퍼 인스턴스를 구성하기 때문에 구성됩니다
16:23
힙은 맵 또는 세트에 센티널 노드를 할당합니다
16:30
이미 존재하는 것에서 이사하더라도 이사하는 것은 여전히 다음과 같아야 합니다
16:36
유효한 상태이므로 빈 노드가 비어 있음을 나타내기 위해 여전히 빈 노드가 필요합니다
16:43
이것은 스코프 잠금 장치의 예입니다
16:50
스코프 잠금은 뮤텍스를 가져다가 뮤텍스를 잠그고 스코프가 끝나면 해제하는 기능입니다

- 16:55
그것을 확장하여 임의의 수의 숫자를 취할 수 있도록 한 논문이 있던 뮤텍스
17:01
가변 템플릿으로 만들어 잠금 또는 음소의 수를 제한합니다
17:08
하지만 적어도 한 공급업체는 이름과 망글링 방식을 사용하여 하나의 변형 템플릿을 망글링했습니다
17:16
일반 템플릿과 달리 실패한 템플릿은 변경해야 했기 때문에 변경해야 했습니다
17:21
예를 들어 스코프 잠금 대신 잠금 가드의 새로운 이름이 있습니다
17:27
이를 구현하고 작동함으로써 발생하는 결과
17:32
사실상 또 다른 정말 흥미로운 예는 최대 t일 때까지 한 번도 생각해 본 적이 없다는 것입니다
17:38
최근 inmax t가 플랫폼에서 사용할 수 있는 가장 넓은 정수입니다
17:45
이는 API에 인코딩된다는 것을 의미하며, 누군가가 intex t를 언급한 후
17:52
최대 t 변화에서는 상황이 깨질 것이라는 의미가 바뀌기 때문에 이제 최대 t 캔에 갇혀 있습니다
17:58
지금 당장 128이 되면 무슨 뜻이든 상관없습니다
18:03
t 그러면 최대 t는 오늘날에도 깨지지 않기 위해 무엇이든 의미해야 합니다
18:12
그래서 이 터널 끝에 빛이 있긴 하지만, 그런 것들이 있습니다
18:18
플랫폼이 예를 들어 새로운 아키텍처로 주요 전환을 겪을 때마다
18:24
또한 이러한 모든 API 선택 사항을 다시 검토하여 고유 포인터의 호출 규칙을 변경할 수 있는 기회가 있습니다
18:30
인스턴스 또는 음을 변경하면 최대 t에서 다른 것들을 알 수 있습니다. 예를 들어, 아이폰일 때요
18:38
예를 들어, 팔 v7에서 팔 64로 변경된 것은 모든 사람이 모든 것을 다시 컴파일해야 했던 예입니다
18:44
사실 애플은 libc 플러스를 업데이트했다고 생각합니다
18:50
API 결정의 일종으로, 또 다른 예로는 win32에서 win64를 얻는 것이 있습니다. 어, i
18:56
아마도 그들이 내린 가장 잘 알려진 구매자 결정이나 변경은 예외 처리였다고 생각합니다
19:01
그것을 일종의 시도라고 부르는 것에서
19:06
실제로 추적하는 위치를 잡기
19:12
64승에서 더 일반적인 테이블 기반 예외 처리로 핸들러를 잡습니다.
19:18
그리고 맥은 최근에 다음과 같은 전환을 이루었습니다
19:23
x8664에서 amd64까지 업데이트가 있었는지는 모르겠지만 업데이트가 완료된 것 같습니다
해결책


- 19:32
음, 그래서 이 음에 대해 무엇을 할 수 있을까요
19:38
한 가지는 사람들이 원하는 모든 좋은 아이디어가 libsy와 bus에서 구현될 수 있다는 것입니다
19:45
또는 다른 표준 라이브러리에서는 매크로에 의해 비활성화되었지만 실제로 lib superfast는 다음과 같은 기능을 가지고 있습니다
19:51
적어도 다른 유형에서는 대체 구현이 있지만 다음을 선택할 수 있습니다
19:56
다음 대규모 아키텍처 업그레이드가 올 때마다 사용할 수 있는 것은 무엇입니까
20:03
이 모든 것이 이미 구현되어 있다는 것을 알고 있습니다. 스위치를 선택하여 사용할 수 있습니다
20:08
um 허브스탑터 제안
20:15
휴대용 API를 사용할 수 있는 언어 기능이 있습니다
20:22
최대 성능을 위해 사용하고 싶은 API 또는 표준 라이브러리의 구현 방법
20:27
우리는 그것을 가지고 있지만, 이제 상호 운용성을 위한 것이니 선택하세요
20:33
이것의 휴대용 버전은 우리가 서로 대화하고 상대방이 무엇이든 다시 변환할 수 있도록 합니다
20:39
그래서 종이가 있어서 n 4028입니다
20:44
또 다른 아이디어는 로더와 링커가 글루 코드를 생성하도록 하는 것입니다
20:50
유형을 변환하거나 변환합니다
20:55
마이크로소프트가 전환할 때 윈도우 64의 윈도우가 그랬던 것처럼
21:00
win64 어, 그들은 파란색 코드를 가지고 있어서 win32 애플리케이션이 여전히 시스템을 호출할 수 있습니다
21:06
시스템 호출을 하면 64비트 시스템 호출로 변환됩니다
21:11
그것은 정말 제한적입니다. 심지어 창문과 창문 64에도 한계가 있었습니다
21:18
어, 만약 그것을 임의의 슈퍼플러스 API에 적용하려고 한다면, 그건 사실상 불가능할 것 같아요
21:26
어, 최근에 또 다른 논문이 있습니다
21:32
제가 제대로 이해했다면 다음과 같이 제안하는 것입니다
21:38
예를 들어 표준 라이브러리에 클래스를 표시하여 다음을 수행합니다

- 21:44에는 가상 인터페이스 래퍼가 자동으로 생성되므로 가상 인터페이스 없이 내부 구현 21:55를 선택할 수 있지만 상호 운용 가능한 운영성을 원할 때는 가상 인터페이스가 있는 것을 선택할 수 있습니다. 22:02에는 가상 인터페이스가 있는 것을 작년의 p212322:09 성능 비용으로 선택하고 싶습니다. 몇 가지 재미있는 예를 말씀드리고 싶습니다. 22:16에는 사람들이 실제로 22:21까지 안정적인 API를 유지하고 있으므로 소스에서 22:26 모든 것을 구축하는 것은 큰 문제가 되지 않지만, 특히 소스에서 표준 라이브러리를 구축하지 않으면 22:33uh에 고정되어 있기 때문에 여전히 22:39에 무엇을 사용하고 있는지 알 수 있습니다. 예를 들어, 표준 라이브러리를 포함한 모든 종속성이 22:44인 경우, 컴파일러도 종속성 스트림의 일부일 수 있습니다. 예를 들어 22:50이라는 단일 레포를 구축할 수 있다면, 22:56이라는 꽤 좋은 방법으로 이 문제를 카펫 아래로 쓸어버리고 존재하지 않는 척할 수 있습니다. 하지만 23:02 실용적인 예를 들어, 이전에 언급한 플러그인과 파이썬 모듈 또는 프로그램이 세 번째 23:09 파티 또는 23:17과의 폐쇄된 소스 종속성이 있을 때 플러그인을 수락하는 경우, 미네소타에서는 win3223:24의 한 부분이 향후 업데이트로부터 자신을 보호하는 방법을 보여주는 예입니다. 첫 번째 23:30 필드는 크기이며, 이를 통과하기 위해 구조의 크기로 필드를 초기화해야 합니다. 이 함수가 할 수 있는 첫 번째 작업은 이 트랙의 크기를 보는 것이고, 23:42는 올바른 구조를 찾을 수 있습니다. 왜냐하면 아마도 몇 가지 새로운 버전이나 23:48 이전 버전을 인식할 수 있기 때문일 수 있기 때문입니다. 또 다른 예는 com23:54입니다. com23:54입니다. 기본적으로 모든 인터페이스를 24:00경에 완전히 동적으로 돌리는 곳이 여전히 24:00경이라는 이야기를 들어본 적이 있는지는 잘 모르겠습니다. 그래서 인터페이스를 완전히 동적으로 쿼리한 후 24:06을 통해 인터페이스를 완전히 동적으로 쿼리하고 24:06에 인터페이스를 조회한 다음 24:06을 y:06에 인터페이스에 문의하면 됩니다당신은 그것이 실패할 수 있다는 것을 알고 있으며, 기본적으로 모든 객체 24:12가 기본적으로 가질 수 있는 인터페이스의 수를 얼마든지 구현할 수 있다는 것을 의미합니다. 이는 24:18v 테이블이나 일종의 가상 함수 인터페이스 24:27과 유사합니다. 아마도 가장 일반적인 방법은 불투명한 타입이나 핌플 양 구현을 사용하는 것일 것입니다. 여기서 24:34 simply는 레이아웃을 구현 세부 사항처럼 내부에 배치하거나, API는 24:41 library의 사용자가 24:46에 도달하지 못한 것에 대한 포인터처럼 보이게 합니다. 그런 다음, 포인터에서 작동하는 모든 함수가 이 경계의 다른 24:52 쪽에 있는 한, 해당 포인터에 대해 작동합니다. 예를 들어, 24:59f open f read f close와 그 패밀리 함수는 예를 들어 25:04입니다

- 25:04 파일 포인터를 실제로 보지 말고 참조하고 그 안에 무엇이 있는지 확인해 보세요. 지금은 불투명한 25:13입니다. 이 파일 포인터는 아마도 제가 가장 좋아하는 도구입니다. 만약 누군가가 시스템 라이브러리에 c + 25:20 API를 실제로 사용했을 때, 보스들이 주변에 있었다면 이 점을 고려했을 것입니다. 그래서 그들은 25:26이 미래에 새로운 가상 기능을 클래스에 추가하고 싶을 수 있다고 생각했습니다. 그래서 그들은 25:31이 더미 v 테이블 항목들을 많이 만들었기 때문에 25:36이 새로운 필드를 추가해야 할 수도 있다고 생각했습니다. 그들은 25:45로 데이터 필드를 확장할 수 있도록 하기 위해 마지막에 패딩을 추가했습니다. 그들의 주요 단점은 gcc 295 API를 기반으로 했다는 것이었습니다. 이 API는 25:52가 형편없어서 컴파일러에서 사용할 수 없다는 것이었습니다. 마지막으로 25:58이라는 도구를 언급하고 싶습니다. abi 컴플라이언스 검사기가 있습니다. abi complement checker가 있습니다. abi complement checker가 있습니다. abi ci uh에서 첫 번째 버전의 무언가를 덤프하고 26:13을 사용하는 것이 좋습니다. 26:18이 기본적으로 호환되는지 확인하여 바이너리 26:25 릴리스 uh를 만들 수 있도록 하고, 모든 사용자들이 26:30이라는 것을 알게 될 것입니다. 또한, 26:36이 많은 오픈 소스 라이브러리를 스캔하여 다음과 같은 좋은 보고서를 제공합니다. i26:43이 liby plus라고 생각하기 때문에 모든 버전을 보고 경고를 줄 수 있습니다. 그러면 26:49가 아래로 내려가서 어떤 심볼이 변경되었는지 보고 심각한지 확인할 수 있습니다. 26:55 정도로 심각한지 여부를 결정할 수 있습니다. 그래서 제 발표를 마치겠습니다. 감사합니다. 이것이 27:01you27:09 어떤 질문이든 27:16이 27:28의 타입을 27:16으로 인코딩하는 것을 제안하는 것을 알고 있습니다. 사실, 공식적인 제안은 아니지만 메일링 리스트에 대한 27:35의 모든 타입을 27:40 해시할 가능성이 있는 내용을 포함하는 것을 포함하는 것을 고려하고 있습니다. 27:52의 문제는 클래스에 대한 맹글 이름이나 링크 이름의 문제는 많은 사람들이 많고, 27:46:52더 이상 작동하지 않는 이유는 27:58입니다. 왜냐하면 클래스를 모르면 28:07 이하의 숫자를 얻을 수 있기 때문입니다. 예를 들어, 당신도 그 문자열을 해시할 수 있습니다. 예를 들어, 공유 라이브러리를 실제로 로드할 때처럼 기호들이 이미 해시된다는 것입니다. 예를 들어, 28:22는 목록을 제대로 스캔하지 않을 것입니다. 이는 해시 검색을 통해 기호들을 찾는 것이지만, Python modules28:31ys python modules28:31yes python modules28:38의 실제 파일 생성과 많은 리눅스를 사용한 네이밍에 관한 파이썬 향상 제안이 무엇인지 언급했거나 문제가 있습니다. 28:44 문제는 매우 오래된 운영 체제에서 매우 오래된 컴파일러를 다루는 것과 같습니다. 예를 들어, 28:51 네, 저는 파이썬에 대한 전문가는 아니지만, 제가 이해하는 바로는 API를 사용하는 이 이니셔티브도 있다는 것입니다


- 29:053 어, 모든 파이썬 세 가지 버전과 29:12 사이에 안정적인 파이썬 API가 있습니다. 이 두 가지 문제를 완화하는 데는 두 가지 방법이 있습니다. 매니 리눅스 예제에서도 29:19에 해당합니다. 리눅스 배포판을 모두 잠그면 이 하나의 API를 사용하는 것이 좋다고 말합니다. 29:26 이 API를 사용하는 것이 좋습니다. 립스틱 zip과 29:31의 구성을 알고 있습니다. 왜냐하면 우리는 여전히 근육 기반 배포판에 문제가 있기 때문입니다. 따라서 전체적인 문제를 해결하지는 못하지만, 29:42 파이썬 문제를 더 간단하게 해결하고 있습니다. 왜냐하면 모든 의존성을 동일한 29:55 프로세스에 연결하지 않고 심볼이 글로벌하기 때문입니다. 그래서 gcc 4:30:01로 하나의 플러그인을 만들고, 표준 스트림에 대해 오래된 cdi를 가진 후 다른 API로 다른 플러그인을 만들고, 내부적으로는 30:08을 사용합니다. 왜냐하면 우리가 이전에 문자열을 호출한 적이 있기 때문입니다. 30:14 같은 프로세스에 문자열을 로드하면 코드 문자열이 없기 때문입니다. 왜냐하면 기본적으로 30:20은 서로 다른 버전의 라이브러리에서 동일한 프로세스로 나올 수 있기 때문입니다. 30:26 이 모든 의존성은 동일한 많은 리눅스 30:31 배포판을 사용해야 한다고 생각합니다. 예를 들어, 오픈 소스 라이브러리나 다른 것을 개발해서 문서화하면 30:56이 되면 c를 사용하거나 30:50을 숨기세요. 하지만 그 31:06um 네, 좋은 질문에 대한 API 전략을 문서화하는 방법에 대한 팁이 있습니다. 안타깝게도 제가 31:14를 수용한 제 관습은 특정 버전 번호 31:19가 특정 버전 번호가 31:19에 연결될 때마다 API를 끊는 것 같고, 그때 API를 끊는 것 같습니다. 왜냐하면 기본적으로 API를 10년 동안 지속된 프로가 있고 10년 된 31:33 같은 실수를 반복해서 10년 된 31:38 소스에서 벗어나면 마음에 들지 않을 정도로 끔찍한 문제가 되기 때문입니다. 예를 들어, 예를 들어 31:38 소스에서 벗어나서 31:44라고 말하지만 가끔은 31:44라고 말하지만, 예를 들어 31:44라고 말하는 경우도 있지만 가끔은 peo:44라고 말하는 것 같습니다라이브러리를 가져가세요. 그들은 그것으로 패키지를 만들고, 31:49는 리눅스 패키지 관리자에게 배포합니다. 그런 다음 다른 누군가가 31:55와 링크를 연결합니다. 그런 다음 다른 바이너리가 링크를 32:02로 변경하도록 패키지를 업데이트하려면 주의해야 한다는 것을 알고 있습니다. 인코더 32:10을 유지해야 하지만, 이는 일반적으로 단일 프로세스에서 서로 다른 라이브러리가 들어오는 것과 동일한 문제입니다. 예를 들어, 라이브러리 버전 ebay가 있는 경우 서로 대화할 수 없거나, 32:22를 발견한 경우와 같이 서로 다른 32:16 의존성을 가집니다. 예를 들어, 데이터에 대한 간단한 호출이나 API 32:38의 인터페이스에서 제공하는 다른 메타데이터를 확장하려는 시도가 있을까요? 32:44의 기본적인 문제는 API가 32:50과 함께 제공되지 않는다는 점입니다

- 32:50
완전한 원칙 소비, 맞아요, 실제로는
32:56
심볼 망글링은 그 중 일부를 제대로 수행하며 더 많은 정보를 인코딩하는 것을 상상할 수 있습니다
33:02
하지만 제가 언급한 언어는 타입의 순방향 선언과 함께
33:09
여전히 푸가 무엇인지 모른 채 푸에게 포인터를 보내는 함수를 호출할 수 있어야 합니다
33:15
헤더가 없고 네 개의 선언문이 없는 미래에는 그 문제를 극복할 수 있을지도 모릅니다
33:36
네, 파란색 코드를 좋아요 번역 코드로 생성하는 것은 정말 어려울 것 같아요
33:43
아마도 제가 생각하는 예시처럼 당신이 합격했다고 상상하는 것은 사실상 불가능할 것입니다
33:48
비틀린 문자열을 함수에 비연속적으로 참조하는 것처럼 스레드를 생성하고 이를 업데이트합니다
33:55
문자열에 연결한 다음 다른 채널을 통해 동기화하면 문자열이 업데이트될 것으로 예상할 수 있습니다
34:00
번역이 있었다면 언제쯤 다시 번역이 이루어졌을까요
34:14
네, 제가 생각하기에 그 목표의 단어는 바로 당신입니다
34:19
적어도 우리가 거기에 도달할 수 있다면 훨씬 더 나아질 거라는 걸 알아요, 네
34:29
구현을 하지만 c를 언급하기만 하면 API 표준의 유형도 마찬가지입니다
34:36
아무 일도 일어나지 않아서 지루합니다. 변하지 않아요, 아니요, 아니요, 아니요, 아니요, 다음 턴 C가 있어서 매우 중요합니다
34:42
당신이 원하는 구현 인터페이스인 cit 뒤에 물건을 넣는 문장 규칙
34:48
그리고 c 인터페이스가 대중에게 변하지 않는 한, c 인터페이스는 변하지 않지만 c가 다음과 같은 기능을 가지고 있지 않다고만 표시됩니다
34:55
표준화된 API는 예를 들어 최대 t에 해당하는 경우 c에서도 문제가 됩니다
35:03
하지만 같은 C 라이브러리를 사용한다면 근육에 대해서는 잘 모르겠지만 다음과 같이 말해야 합니다
35:08
튤립 c를 사용하면 오래된 바이너리가 여전히 실행되도록 보장하고 간단한 버전을 사용하여 다음을 수행할 수 있습니다
35:16
50년 전 바이너리를 실행합니다. 네, 네, 하지만 스탠딩 스트링은 복잡합니다
35:24
네, 맞아요, 제 말은 립스틱에 두 줄이 들어 있다는 거예요
35:30
그들은 전통적인 대처 방식을 가지고 있으며, 그 다음에는 새로운 작은 문자열 최적화 버전을 가지고 있습니다
35:37
매크로로 선택하면 두 가지를 연결하여 서로 다른 것을 선택하면
35:43
작동하지만 링커 오류가 발생하므로 CK를 특별히 언급한 것이므로 괜찮습니다
35:49
네, 제 말은 기본적으로 인터페이스가 간단할수록 이 문제가 발생할 가능성이 적다는 것도 알 수 있습니다

- 35:55
c 플러스 인터페이스를 가질 수도 있지만 여드름이 있어서 모든 구현 세부 사항을 숨길 수 있습니다
36:01
세탁실은 포인터만 사용하면 됩니다
36:06
네, 맞아요. 하지만 포인터를 사용해도 그것은
36:13
예를 들어, 윈도우 아래에서는 반드시 동일한 C 라이브러리를 사용하지 않을 수 있으므로 보통 배송합니다
36:19
또는 사용할 C 라이브러리를 정의한 다음 무료 또는 malloc을 사용할 수 없습니다
36:24
한 도서관에서는 독백을 하고 다른 도서관에서는 독백을 하기 때문에 미묘한 부분도 많이 감수해야 합니다
36:29
c로 작업할 때 API가 없으므로 동일한 c 라이브러리를 사용하기만 하면 됩니다
36:36
당신의 종류는 안전합니다. 예전에는 글래스고를 보곤 했지만, 창문이 전혀 없다고 합니다
36:43
보고 싶으시다면, Microsoft에서 "우리가 이제 봤어요"라고 말하는 것이 바로 최근의 일입니다
36:48
네, 정확히 여기서 그때까지 그들은 만약 이 c 부분을 c 신성 모독과 결합하고 싶다면 여기서 신성 모독이라고 말했습니다
36:56
창문에서 전혀 사실을 볼 필요가 없습니다
37:02
지금은 바꾸기에 좋은 시기가 아니라고 생각합니다
37:11
[박수]
