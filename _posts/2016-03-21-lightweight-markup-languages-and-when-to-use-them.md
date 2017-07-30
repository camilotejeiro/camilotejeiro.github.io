---
title: Lightweight Markup Languages and When to Use Them
---

_Please note these are purely my opinions._

> Use simple tools for simple tasks and always simplify tasks. Rinse and repeat.

First, [read this](https://en.wikipedia.org/wiki/Markup_language) if you don't
know what a markup language is, and then 
[read this](https://en.wikipedia.org/wiki/Lightweight_markup_language) 

Did you read it? Excellent. So over the past couple of days I have been doing
some research to decide upon a lightweight markup language for my documentation
purposes.

From my research it seems:

## For Simple Notes

e.g. for your text-pad, note-pad, for keeping track of ideas ...etc

**Use** [**Text linked_files**](https://en.wikipedia.org/wiki/Text_file): for cases
where you are interested in simplicity of form and content and you don't care
too much about visual appearance and presentation.

As a simple rule, always start with raw **text-linked_files **by default. If you feel
you need more,  you can always copy and paste to other formats later on.

## For Short Readmes or Prose to Publish on the Web

e.g. Readmes for projects on GitHub, BitBucket, or quick blog posts ...etc.

**Use [Markdown](https://en.wikipedia.org/wiki/Markdown):** this is basically
the lightest markup language that exists, however it provides quite a bit of
flexibility for formatting short documents (Headings, lists, bold, italics ...
etc).

But remember **do not** use Markdown for longer documents, it is really not
suited for this (it gets hard to maintain really quickly). Also Markdown was
primarily designed for web content (HTML) so if you are preparing documents for
print (e.g. pdf) there are better formats especially suited for this, please see
below.

> Markdown is serviceable for simple short prose, but the instant you need more
> than basic formatting, you're on your own.

## For Documents to Send to Non-Technical (Office) Users

Use a [WYSIWYG](https://en.wikipedia.org/wiki/WYSIWYG) document 
(e.g. [libre office](https://en.wikipedia.org/wiki/LibreOffice)) 
in open format so they can edit it.

_*Not a lightweight markup language per-se, but in the interest of preserving
friendships and peace  with people used to working with MS Office that swear by
it (Why? ... oh let's not go there)._

## For Long Documentation Requiring Collaboration and Displayed on the Web.

**Use [AsciiDoc](http://www.methods.co.nz/asciidoc/) or
[reStructuredText](http://docutils.sourceforge.net/rst.html)**: These are more
flexible light markup languages especially suited for this purpose. Out in the
field they are used for writing user manuals,  getting started guides, technical
documentation, ebooks ..etc. (Here is an 
[interesting article](http://asciidoctor.org/docs/what-is-asciidoc/) on AsciiDoc)

> Markdown is great to write small and simple documents. But
> ReST/ASCIIdoc are much better when you want more complex, richer docs.

## For Individual Professional Documents for Print.

**Use [LaTeX](https://en.wikipedia.org/wiki/LaTeX)**: for both flexibility and
excellent quality documents (especially if they include mathematics) for
publication in print (i.e. for PDF documents that are meant to be
displayed/printed as pages).

e.g. for research papers, academic dissertation, Journal papers, curriculum
vitae, resume ...etc.

> LaTeX generates publication quality documents and formulas that look great on
> paper.

I have personally used LaTeX quite a bit and I really like it, however for
collaboration LaTeX is not the best candidate (though there are some
[alternatives](https://www.sharelatex.com/) if you really want to go this
route): there is a steep learning curve for beginners and you have to download
about 1GB just to be able to start working with it locally.

Hope this helps,

Did I miss anything? leave your comments below,

{% include issues_comments.md %}
