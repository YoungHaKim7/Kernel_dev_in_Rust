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

- 
